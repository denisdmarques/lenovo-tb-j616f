/*
 * mtu3.h - MediaTek USB3 DRD header
 *
 * Copyright (C) 2016 MediaTek Inc.
 *
 * Author: Chunfeng Yun <chunfeng.yun@mediatek.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MTU3_H__
#define __MTU3_H__

#include <linux/device.h>
#include <linux/dmapool.h>
#include <linux/extcon.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/phy/phy.h>
#include <linux/regulator/consumer.h>
#include <linux/usb.h>
#include <linux/usb/ch9.h>
#include <linux/usb/class-dual-role.h>
#include <linux/usb/gadget.h>
#include <linux/usb/otg.h>

struct mtu3;
struct mtu3_ep;
struct mtu3_request;

#include "mtu3_hw_regs.h"
#include "mtu3_qmu.h"

#define	MU3D_EP_TXCR0(epnum)	(U3D_TX1CSR0 + (((epnum) - 1) * 0x10))
#define	MU3D_EP_TXCR1(epnum)	(U3D_TX1CSR1 + (((epnum) - 1) * 0x10))
#define	MU3D_EP_TXCR2(epnum)	(U3D_TX1CSR2 + (((epnum) - 1) * 0x10))

#define	MU3D_EP_RXCR0(epnum)	(U3D_RX1CSR0 + (((epnum) - 1) * 0x10))
#define	MU3D_EP_RXCR1(epnum)	(U3D_RX1CSR1 + (((epnum) - 1) * 0x10))
#define	MU3D_EP_RXCR2(epnum)	(U3D_RX1CSR2 + (((epnum) - 1) * 0x10))

#define USB_QMU_RQCSR(epnum)	(U3D_RXQCSR1 + (((epnum) - 1) * 0x10))
#define USB_QMU_RQSAR(epnum)	(U3D_RXQSAR1 + (((epnum) - 1) * 0x10))
#define USB_QMU_RQCPR(epnum)	(U3D_RXQCPR1 + (((epnum) - 1) * 0x10))
#define USB_QMU_RXQHIAR1(epnum)	(U3D_RXQHIAR1 + (((epnum) - 1) * 0x4))

#define USB_QMU_TQCSR(epnum)	(U3D_TXQCSR1 + (((epnum) - 1) * 0x10))
#define USB_QMU_TQSAR(epnum)	(U3D_TXQSAR1 + (((epnum) - 1) * 0x10))
#define USB_QMU_TQCPR(epnum)	(U3D_TXQCPR1 + (((epnum) - 1) * 0x10))
#define USB_QMU_TXQHIAR1(epnum)	(U3D_TXQHIAR1 + (((epnum) - 1) * 0x4))

#define QMU_GPD_BUF_HI(x)	(((x) & 0xf))
#define QMU_GPD_NEXT_HI(x)	(((x) & 0xf) << 4)


#define SSUSB_U3_CTRL(p)	(U3D_SSUSB_U3_CTRL_0P + ((p) * 0x08))
#define SSUSB_U2_CTRL(p)	(U3D_SSUSB_U2_CTRL_0P + ((p) * 0x08))

#define MTU3_DRIVER_NAME	"mtu3"
#define	DMA_ADDR_INVALID	(~(dma_addr_t)0)

#define MTU3_EP_ENABLED		BIT(0)
#define MTU3_EP_STALL		BIT(1)
#define MTU3_EP_WEDGE		BIT(2)
#define MTU3_EP_BUSY		BIT(3)

#define K_EMERG		0
#define K_ALET		1
#define K_CRIT		2
#define K_ERR		3
#define K_WARNIN	4
#define K_NOTICE	5
#define K_INFO		6
#define K_DEBUG		7

#ifdef CONFIG_USB_MTU3_PLAT_PHONE
#define MTU3_U3_IP_SLOT_DEFAULT 2
#define MTU3_LTSSM_INTR_EN (U3_RESUME_INTR | U3_LFPS_TMOUT_INTR | \
		VBUS_FALL_INTR | VBUS_RISE_INTR | \
		/*RXDET_SUCCESS_INTR |*/ EXIT_U3_INTR | \
		ENTER_U3_INTR | ENTER_U0_INTR | \
		RECOVERY_INTR | WARM_RST_INTR | \
		HOT_RST_INTR | LOOPBACK_INTR | \
		COMPLIANCE_INTR | SS_DISABLE_INTR | \
		SS_INACTIVE_INTR | VBUS_RISE_INTR | \
		VBUS_FALL_INTR)
/*Set the debug level at musb_core.c*/
extern u32 debug_level;
#define mtu3_printk(level, fmt, args...) do { \
			if (debug_level >= level) { \
				pr_notice("[MTU3]" fmt, ## args); \
			} \
		} while (0)

#else
#define MTU3_U3_IP_SLOT_DEFAULT 2
#define mtu3_printk(level, fmt, args...) do {} while (0)
#endif

#define MTU3_U2_IP_SLOT_DEFAULT 1

/**
 * Normally the device works on HS or SS, to simplify fifo management,
 * devide fifo into some 512B parts, use bitmap to manage it; And
 * 128 bits size of bitmap is large enough, that means it can manage
 * up to 64KB fifo size.
 * NOTE: MTU3_EP_FIFO_UNIT should be power of two
 */
#define MTU3_EP_FIFO_UNIT		(1 << 9)
#define MTU3_FIFO_BIT_SIZE		128
#define MTU3_U2_IP_EP0_FIFO_SIZE	64

/**
 * Maximum size of ep0 response buffer for ch9 requests,
 * the SET_SEL request uses 6 so far, and GET_STATUS is 2
 */
#define EP0_RESPONSE_BUF  6

/**
 * MTU3_DR_FORCE_NONE: automatically switch host and periperal mode
 *		by IDPIN signal.
 * MTU3_DR_FORCE_HOST: force to enter host mode and override OTG
 *		IDPIN signal.
 * MTU3_DR_FORCE_DEVICE: force to enter peripheral mode.
 */
enum mtu3_dr_force_mode {
	MTU3_DR_FORCE_NONE = 0,
	MTU3_DR_FORCE_HOST,
	MTU3_DR_FORCE_DEVICE,
};

/* device operated link and speed got from DEVICE_CONF register */
enum mtu3_speed {
	MTU3_SPEED_INACTIVE = 0,
	MTU3_SPEED_FULL = 1,
	MTU3_SPEED_HIGH = 3,
	MTU3_SPEED_SUPER = 4,
};

/**
 * @MU3D_EP0_STATE_SETUP: waits for SETUP or received a SETUP
 *		without data stage.
 * @MU3D_EP0_STATE_TX: IN data stage
 * @MU3D_EP0_STATE_RX: OUT data stage
 * @MU3D_EP0_STATE_TX_END: the last IN data is transferred, and
 *		waits for its completion interrupt
 * @MU3D_EP0_STATE_STALL: ep0 is in stall status, will be auto-cleared
 *		after receives a SETUP.
 */
enum mtu3_g_ep0_state {
	MU3D_EP0_STATE_SETUP = 1,
	MU3D_EP0_STATE_TX,
	MU3D_EP0_STATE_RX,
	MU3D_EP0_STATE_TX_END,
	MU3D_EP0_STATE_STALL,
};

enum fpga_phy_version {
	NO_PHY = 0,
	A60930,
	A60979,
	A60931,
	A60862,
};

/**
 * @base: the base address of fifo
 * @limit: the bitmap size in bits
 * @bitmap: fifo bitmap in unit of @MTU3_EP_FIFO_UNIT
 */
struct mtu3_fifo_info {
	u32 base;
	u32 limit;
	DECLARE_BITMAP(bitmap, MTU3_FIFO_BIT_SIZE);
};

/**
 * General Purpose Descriptor (GPD):
 *	The format of TX GPD is a little different from RX one.
 *	And the size of GPD is 16 bytes.
 *
 * @flag:
 *	bit0: Hardware Own (HWO)
 *	bit1: Buffer Descriptor Present (BDP), always 0, BD is not supported
 *	bit2: Bypass (BPS), 1: HW skips this GPD if HWO = 1
 *	bit7: Interrupt On Completion (IOC)
 * @chksum: This is used to validate the contents of this GPD;
 *	If TXQ_CS_EN / RXQ_CS_EN bit is set, an interrupt is issued
 *	when checksum validation fails;
 *	Checksum value is calculated over the 16 bytes of the GPD by default;
 * @data_buf_len (RX ONLY): This value indicates the length of
 *	the assigned data buffer
 * @next_gpd: Physical address of the next GPD
 * @buffer: Physical address of the data buffer
 * @buf_len:
 *	(TX): This value indicates the length of the assigned data buffer
 *	(RX): The total length of data received
 * @ext_len: reserved
 * @ext_flag:
 *	bit5 (TX ONLY): Zero Length Packet (ZLP),
 */
struct qmu_gpd {
	__u8 flag;
	__u8 chksum;
	__le16 data_buf_len;
	__le32 next_gpd;
	__le32 buffer;
	__le16 buf_len;
	__u8 ext_len;
	__u8 ext_flag;
} __packed;

/**
 * dma: physical base address of GPD segment
 * start: virtual base address of GPD segment
 * end: the last GPD element
 * enqueue: the first empty GPD to use
 * dequeue: the first completed GPD serviced by ISR
 * NOTE: the size of GPD ring should be >= 2
 */
struct mtu3_gpd_ring {
	dma_addr_t dma;
	struct qmu_gpd *start;
	struct qmu_gpd *end;
	struct qmu_gpd *enqueue;
	struct qmu_gpd *dequeue;
};

/**
 * @vbus: vbus 5V used by host mode
 * @edev: external connector used to detect vbus and iddig changes
 * @vbus_nb: notifier for vbus detection
 * @vbus_nb: notifier for iddig(idpin) detection
 * @extcon_reg_dwork: delay work for extcon notifier register, waiting for
 *		xHCI driver initialization, it's necessary for system bootup
 *		as device.
 * @is_u3_drd: whether port0 supports usb3.0 dual-role device or not
 * @id_*: used to maually switch between host and device modes by idpin
 * @manual_drd_enabled: it's true when supports dual-role device by debugfs
 *		to switch host/device modes depending on user input.
 */
struct otg_switch_mtk {
	struct regulator *vbus;
	struct extcon_dev *edev;
	struct notifier_block vbus_nb;
	struct notifier_block id_nb;
	struct delayed_work extcon_reg_dwork;
	bool is_u3_drd;
	bool is_u3h_drd;
	/* dual-role switch by debugfs */
	struct pinctrl *id_pinctrl;
	struct pinctrl_state *id_float;
	struct pinctrl_state *id_ground;
	bool manual_drd_enabled;
	struct delayed_work dr_work;
	struct workqueue_struct *dr_workq;
	unsigned int usb_mode;
	unsigned int desire_usb_mode;
	spinlock_t dr_lock;
};

/**
 * @mac_base: register base address of device MAC, exclude xHCI's
 * @ippc_base: register base address of IP Power and Clock interface (IPPC)
 * @vusb33: usb3.3V shared by device/host IP
 * @sys_clk: system clock of mtu3, shared by device/host IP
 * @ref_clk: reference clock
 * @mcu_clk: mcu_bus_ck clock for AHB bus etc
 * @dma_clk: dma_bus_ck clock for AXI bus etc
 * @host_clk: host_clk clock for host
 * @dr_mode: works in which mode:
 *		host only, device only or dual-role mode
 * @u2_ports: number of usb2.0 host ports
 * @u3_ports: number of usb3.0 host ports
 * @dbgfs_root: only used when supports manual dual-role switch via debugfs
 * @wakeup_en: it's true when supports remote wakeup in host mode
 * @wk_deb_p0: port0's wakeup debounce clock
 * @wk_deb_p1: it's optional, and depends on port1 is supported or not
 */
struct ssusb_mtk {
	struct device *dev;
	struct mtu3 *u3d;
	void __iomem *mac_base;
	void __iomem *ippc_base;
	void __iomem *xhci_base;
	struct phy **phys;
	int num_phys;
	/* common power & clock */
	struct regulator *vusb33;
	struct clk *sys_clk;
	struct clk *ref_clk;
	struct clk *mcu_clk;
	struct clk *dma_clk;
	struct clk *host_clk;
	struct clk *xhci_clk;
	/* otg */
	struct otg_switch_mtk otg_switch;
	struct delayed_work clk_ctl_dwork;
	struct delayed_work otg_detect_dwork;
	enum usb_dr_mode dr_mode;
	bool is_host;
	bool u3ports_disable;
	int u2_ports;
	int u3_ports;
	struct dentry *dbgfs_root;
	/* usb wakeup for host mode */
	bool wakeup_en;
	struct regmap *uwk;
	u32 uwk_reg_base;
	u32 uwk_vers;
	/* keep clock and phy always on*/
	bool keep_ao;
	/* keep infra power on*/
	bool infra_on;
	bool force_vbus;
	bool noise_still_tr;
	bool u1u2_disable;
	bool u3_loopb_support;
	struct clk *wk_deb_p0;
	struct clk *wk_deb_p1;
	struct regmap *pericfg;
	struct dual_role_phy_instance *drp_inst;
	enum mtu3_dr_force_mode drp_state;
	struct charger_device *chg_dev;
	void *priv_data;
	enum fpga_phy_version fpga_phy_ver;
    bool otg_enable;
};

/**
 * @fifo_size: it is (@slot + 1) * @fifo_seg_size
 * @fifo_seg_size: it is roundup_pow_of_two(@maxp)
 */
struct mtu3_ep {
	struct usb_ep ep;
	char name[12];
	struct mtu3 *mtu;
	u8 epnum;
	u8 type;
	u8 is_in;
	u16 maxp;
	int slot;
	u32 fifo_size;
	u32 fifo_addr;
	u32 fifo_seg_size;
	struct mtu3_fifo_info *fifo;

	struct list_head req_list;
	struct mtu3_gpd_ring gpd_ring;
	const struct usb_ss_ep_comp_descriptor *comp_desc;
	const struct usb_endpoint_descriptor *desc;

	int flags;
	u8 wedged;
	u8 busy;
};

struct mtu3_request {
	struct usb_request request;
	struct list_head list;
	struct mtu3_ep *mep;
	struct mtu3 *mtu;
	struct qmu_gpd *gpd;
	int epnum;
};

static inline struct ssusb_mtk *dev_to_ssusb(struct device *dev)
{
	return dev_get_drvdata(dev);
}

/**
 * struct mtu3 - device driver instance data.
 * @slot: MTU3_U2_IP_SLOT_DEFAULT for U2 IP only,
 *		MTU3_U3_IP_SLOT_DEFAULT for U3 IP
 * @may_wakeup: means device's remote wakeup is enabled
 * @is_self_powered: is reported in device status and the config descriptor
 * @ep0_req: dummy request used while handling standard USB requests
 *		for GET_STATUS and SET_SEL
 * @setup_buf: ep0 response buffer for GET_STATUS and SET_SEL requests
 */
struct mtu3 {
	spinlock_t lock;
	struct ssusb_mtk *ssusb;
	struct device *dev;
	void __iomem *mac_base;
	void __iomem *ippc_base;
	int irq;

	struct mtu3_fifo_info tx_fifo;
	struct mtu3_fifo_info rx_fifo;

	struct mtu3_ep *ep_array;
	struct mtu3_ep *in_eps;
	struct mtu3_ep *out_eps;
	struct mtu3_ep *ep0;
	int num_eps;
	int slot;
	int active_ep;

	struct dma_pool	*qmu_gpd_pool;
	enum mtu3_g_ep0_state ep0_state;
	struct usb_gadget g;	/* the gadget */
	struct usb_gadget_driver *gadget_driver;
	struct mtu3_request ep0_req;
	u8 setup_buf[EP0_RESPONSE_BUF];
	u32 max_speed;

	unsigned is_active:1;
	unsigned may_wakeup:1;
	unsigned is_self_powered:1;
	unsigned test_mode:1;
	unsigned softconnect:1;
	unsigned u1_enable:1;
	unsigned u2_enable:1;
	unsigned is_u3_ip:1;
	unsigned is_36bit:1;
	u8 address;
	u8 test_mode_nr;
	u32 hw_version;

	struct delayed_work check_ltssm_work;
};

static inline struct mtu3 *gadget_to_mtu3(struct usb_gadget *g)
{
	return container_of(g, struct mtu3, g);
}

static inline int is_first_entry(const struct list_head *list,
	const struct list_head *head)
{
	return list_is_last(head, list);
}

static inline struct mtu3_request *to_mtu3_request(struct usb_request *req)
{
	return req ? container_of(req, struct mtu3_request, request) : NULL;
}

static inline struct mtu3_ep *to_mtu3_ep(struct usb_ep *ep)
{
	return ep ? container_of(ep, struct mtu3_ep, ep) : NULL;
}

static inline struct mtu3_request *next_request(struct mtu3_ep *mep)
{
	return list_first_entry_or_null(&mep->req_list, struct mtu3_request,
					list);
}

static inline void mtu3_writel(void __iomem *base, u32 offset, u32 data)
{
	writel(data, base + offset);
}

static inline u32 mtu3_readl(void __iomem *base, u32 offset)
{
	return readl(base + offset);
}

static inline void mtu3_setbits(void __iomem *base, u32 offset, u32 bits)
{
	void __iomem *addr = base + offset;
	u32 tmp = readl(addr);

	writel((tmp | (bits)), addr);
}

static inline void mtu3_clrbits(void __iomem *base, u32 offset, u32 bits)
{
	void __iomem *addr = base + offset;
	u32 tmp = readl(addr);

	writel((tmp & ~(bits)), addr);
}

int ssusb_check_clocks(struct ssusb_mtk *ssusb, u32 ex_clks);
struct usb_request *mtu3_alloc_request(struct usb_ep *ep, gfp_t gfp_flags);
void mtu3_free_request(struct usb_ep *ep, struct usb_request *req);
void mtu3_req_complete(struct mtu3_ep *mep,
		struct usb_request *req, int status);

int mtu3_config_ep(struct mtu3 *mtu, struct mtu3_ep *mep,
		int interval, int burst, int mult);
void mtu3_deconfig_ep(struct mtu3 *mtu, struct mtu3_ep *mep);
void mtu3_ep_stall_set(struct mtu3_ep *mep, bool set);
void mtu3_ep0_setup(struct mtu3 *mtu);
void mtu3_start(struct mtu3 *mtu);
void mtu3_stop(struct mtu3 *mtu);
void mtu3_dev_on_off(struct mtu3 *mtu, int is_on);
void mtu3_nuke_all_ep(struct mtu3 *mtu);

int mtu3_gadget_setup(struct mtu3 *mtu);
void mtu3_gadget_cleanup(struct mtu3 *mtu);
void mtu3_gadget_reset(struct mtu3 *mtu);
void mtu3_gadget_suspend(struct mtu3 *mtu);
void mtu3_gadget_resume(struct mtu3 *mtu);
void mtu3_gadget_disconnect(struct mtu3 *mtu);

irqreturn_t mtu3_ep0_isr(struct mtu3 *mtu);
extern const struct usb_ep_ops mtu3_ep0_ops;

#if !IS_ENABLED(CONFIG_USB_MTU3_PLAT_PHONE)
int ssusb_clks_enable(struct ssusb_mtk *ssusb);
void ssusb_clks_disable(struct ssusb_mtk *ssusb);
int ssusb_phy_power_on(struct ssusb_mtk *ssusb);
void ssusb_phy_power_off(struct ssusb_mtk *ssusb);
void ssusb_ip_sw_reset(struct ssusb_mtk *ssusb);
#else
extern void mtu3_check_ltssm_work(struct work_struct *data);
extern bool mtu3_hal_is_vbus_exist(void);
extern void disconnect_check(struct mtu3 *mtu);
extern bool is_saving_mode(void);
extern unsigned int mtu3_cable_mode;
/* USB working mode */
enum cable_mode {
	CABLE_MODE_CHRG_ONLY = 0,
	CABLE_MODE_NORMAL,
	CABLE_MODE_HOST_ONLY,
	CABLE_MODE_FORCEON,
	CABLE_MODE_MAX
};
#endif

#endif

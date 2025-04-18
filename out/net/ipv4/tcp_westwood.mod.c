#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xdeeaadc, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa18513e8, __VMLINUX_SYMBOL_STR(tcp_reno_undo_cwnd) },
	{ 0x7eaa6f88, __VMLINUX_SYMBOL_STR(tcp_reno_cong_avoid) },
	{ 0x5f17ceef, __VMLINUX_SYMBOL_STR(tcp_reno_ssthresh) },
	{ 0x7f24de73, __VMLINUX_SYMBOL_STR(jiffies_to_usecs) },
	{ 0xf1969a8e, __VMLINUX_SYMBOL_STR(__usecs_to_jiffies) },
	{ 0x526c3a6c, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x1fd2a7cc, __VMLINUX_SYMBOL_STR(tcp_unregister_congestion_control) },
	{ 0x11ae8d02, __VMLINUX_SYMBOL_STR(tcp_register_congestion_control) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "96E8D58AC19F8B70304E213");

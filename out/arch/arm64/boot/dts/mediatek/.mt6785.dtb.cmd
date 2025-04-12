cmd_arch/arm64/boot/dts/mediatek/mt6785.dtb := mkdir -p arch/arm64/boot/dts/mediatek/ ; /home/chenyl6/p11-plus-s-kernel/wifi/kernel-4.14/../prebuilts/clang/host/linux-x86/clang-r383902/bin/clang -E -Wp,-MD,arch/arm64/boot/dts/mediatek/.mt6785.dtb.d.pre.tmp -nostdinc -I../scripts/dtc/include-prefixes -I../arch/arm64/boot/dts -I../arch/arm64/boot/dts/include -I./include/ -Iarch/arm64/boot/dts -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/mediatek/.mt6785.dtb.dts.tmp ../arch/arm64/boot/dts/mediatek/mt6785.dts ; ../scripts/dtc/dtc_overlay -@ -O dtb -o arch/arm64/boot/dts/mediatek/mt6785.dtb -b 0 -i../arch/arm64/boot/dts/mediatek/ -i../scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-simple_bus_reg -Wno-unit_address_format -Wno-pci_bridge -Wno-pci_device_bus_num -Wno-pci_device_reg  -d arch/arm64/boot/dts/mediatek/.mt6785.dtb.d.dtc.tmp arch/arm64/boot/dts/mediatek/.mt6785.dtb.dts.tmp ; cat arch/arm64/boot/dts/mediatek/.mt6785.dtb.d.pre.tmp arch/arm64/boot/dts/mediatek/.mt6785.dtb.d.dtc.tmp > arch/arm64/boot/dts/mediatek/.mt6785.dtb.d

source_arch/arm64/boot/dts/mediatek/mt6785.dtb := ../arch/arm64/boot/dts/mediatek/mt6785.dts

deps_arch/arm64/boot/dts/mediatek/mt6785.dtb := \
    $(wildcard include/config/mtk/gmo/ram/optimize.h) \
    $(wildcard include/config/mtk/met/mem/alloc.h) \
    $(wildcard include/config/mtk/iommu/v2.h) \
    $(wildcard include/config/mtk/m4u.h) \
    $(wildcard include/config/mtk/mt6382/dbg.h) \
    $(wildcard include/config/mtk/sec/video/path/support.h) \
    $(wildcard include/config/mtk/cam/security/support.h) \
    $(wildcard include/config/base.h) \
    $(wildcard include/config/target/project/p522.h) \
    $(wildcard include/config/target/project/p530.h) \
    $(wildcard include/config/fpga/early/porting.h) \
    $(wildcard include/config/mtk/gauge/version.h) \
    $(wildcard include/config/mtk/enable/geniezone.h) \
  ../scripts/dtc/include-prefixes/dt-bindings/clock/mt6785-clk.h \
    $(wildcard include/config/nr/clk.h) \
  ../scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  ../scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  ../scripts/dtc/include-prefixes/dt-bindings/mmc/mt6785-msdc.h \
  ../scripts/dtc/include-prefixes/dt-bindings/pinctrl/mt6785-pinfunc.h \
  ../scripts/dtc/include-prefixes/dt-bindings/pinctrl/mt65xx.h \
  ../scripts/dtc/include-prefixes/dt-bindings/memory/mt6785-larb-port.h \
    $(wildcard include/config/mtk/iommu/pgtable/ext.h) \
  ../scripts/dtc/include-prefixes/dt-bindings/gce/mt6785-gce.h \
    $(wildcard include/config/dirty.h) \
  ../scripts/dtc/include-prefixes/dt-bindings/gce/mt6382-gce.h \
  ../scripts/dtc/include-prefixes/dt-bindings/iio/mt635x-auxadc.h \
  ../scripts/dtc/include-prefixes/dt-bindings/mfd/mt6359-irq.h \
  ../arch/arm64/boot/dts/mediatek/bat_setting/mt6785_battery_prop.dtsi \
  ../arch/arm64/boot/dts/mediatek/bat_setting/mt6785_battery_table.dtsi \
  ../arch/arm64/boot/dts/mediatek/bat_setting/mt6785_battery_prop_dim2_ext.dtsi \
  ../arch/arm64/boot/dts/mediatek/mt6359.dtsi \
  ../arch/arm64/boot/dts/mediatek/cust_mt6785_msdc.dtsi \
  ../arch/arm64/boot/dts/mediatek/mt6360.dtsi \
  ../arch/arm64/boot/dts/mediatek/mt6360_pd.dtsi \
  ../arch/arm64/boot/dts/mediatek/trusty.dtsi \

arch/arm64/boot/dts/mediatek/mt6785.dtb: $(deps_arch/arm64/boot/dts/mediatek/mt6785.dtb)

$(deps_arch/arm64/boot/dts/mediatek/mt6785.dtb):

cmd_drivers/misc/mediatek/lcm/lcm_common.o := /home/chenyl6/p11-plus-s-kernel/wifi/kernel-4.14/../prebuilts/clang/host/linux-x86/clang-r383902/bin/clang -Wp,-MD,drivers/misc/mediatek/lcm/.lcm_common.o.d  -nostdinc -isystem /home/chenyl6/p11-plus-s-kernel/wifi/prebuilts/clang/host/linux-x86/clang-r383902/lib64/clang/11.0.1/include -I../arch/arm64/include -I./arch/arm64/include/generated  -I../include -I../drivers/misc/mediatek/include -I./include -I../arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I../include/uapi -I./include/generated/uapi -include ../include/linux/kconfig.h  -I../drivers/misc/mediatek/lcm -Idrivers/misc/mediatek/lcm -D__KERNEL__ -Qunused-arguments -mlittle-endian -DKASAN_SHADOW_SCALE_SHIFT=3 -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 --target=aarch64-linux-gnu --prefix=/home/chenyl6/p11-plus-s-kernel/wifi/kernel-4.14/../prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9.1/bin/ --gcc-toolchain=/home/chenyl6/p11-plus-s-kernel/wifi/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9.1 -no-integrated-as -Werror=unknown-warning-option -fno-PIE -mno-implicit-float -DCONFIG_AS_LSE=1 -fno-asynchronous-unwind-tables -fno-pic -Wno-asm-operand-widths -DKASAN_SHADOW_SCALE_SHIFT=3 -fno-delete-null-pointer-checks -Wno-int-in-bool-context -Wno-address-of-packed-member -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2800 -fstack-protector-strong -Wno-format-invalid-specifier -Wno-gnu -Wno-duplicate-decl-specifier -Wno-tautological-compare -mno-global-merge -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -Wno-array-bounds -fno-strict-overflow -fno-merge-all-constants -fno-stack-check -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -fmacro-prefix-map=../= -Wno-initializer-overrides -Wno-unused-value -Wno-format -Wno-sign-compare -Wno-format-zero-length -Wno-uninitialized -Werror  -I../drivers/misc/mediatek/include  -I../drivers/misc/mediatek/include/mt-plat/mt6785/include/  -I../drivers/misc/mediatek/include/mt-plat/  -I../drivers/mmc/host/mediatek/mt6785  -I../drivers/misc/mediatek/lcm/inc  -I../drivers/misc/mediatek/video/mt6785/dispsys  -I../drivers/misc/mediatek/video/mt6785/dispsys/mt6735  -I../drivers/misc/mediatek/video/mt6785/videox  -I../drivers/misc/mediatek/video/include -DHX83102P_FHDP_DSI_VDO_BOE_P522 -DNT36523W_FHDP_DSI_VDO_BOE_P522 -DNT36523W_FHDP_DSI_VDO_INX_P522 -DMTK_LCM_PHYSICAL_ROTATION=\"\"    -DKBUILD_BASENAME='"lcm_common"'  -DKBUILD_MODNAME='"lcm_common"' -c -o drivers/misc/mediatek/lcm/.tmp_lcm_common.o ../drivers/misc/mediatek/lcm/lcm_common.c

source_drivers/misc/mediatek/lcm/lcm_common.o := ../drivers/misc/mediatek/lcm/lcm_common.c

deps_drivers/misc/mediatek/lcm/lcm_common.o := \
  ../include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  ../include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/retpoline.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  ../include/linux/compiler-clang.h \
    $(wildcard include/config/lto/clang.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \

drivers/misc/mediatek/lcm/lcm_common.o: $(deps_drivers/misc/mediatek/lcm/lcm_common.o)

$(deps_drivers/misc/mediatek/lcm/lcm_common.o):

cmd_arch/arm64/kernel/vdso/vdso.lds := /home/chenyl6/p11-plus-s-kernel/wifi/kernel-4.14/../prebuilts/clang/host/linux-x86/clang-r383902/bin/clang -E -Wp,-MD,arch/arm64/kernel/vdso/.vdso.lds.d  -nostdinc -isystem /home/chenyl6/p11-plus-s-kernel/wifi/prebuilts/clang/host/linux-x86/clang-r383902/lib64/clang/11.0.1/include -I../arch/arm64/include -I./arch/arm64/include/generated  -I../include -I../drivers/misc/mediatek/include -I./include -I../arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I../include/uapi -I./include/generated/uapi -include ../include/linux/kconfig.h -D__KERNEL__ -Qunused-arguments -mlittle-endian -DKASAN_SHADOW_SCALE_SHIFT=3 -P -C -Uarm64 -P -Uarm64 -D__ASSEMBLY__ -DLINKER_SCRIPT -o arch/arm64/kernel/vdso/vdso.lds ../arch/arm64/kernel/vdso/vdso.lds.S

source_arch/arm64/kernel/vdso/vdso.lds := ../arch/arm64/kernel/vdso/vdso.lds.S

deps_arch/arm64/kernel/vdso/vdso.lds := \
  ../include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  ../include/uapi/linux/const.h \
  ../arch/arm64/include/asm/page.h \
    $(wildcard include/config/have/arch/pfn/valid.h) \
  ../arch/arm64/include/asm/page-def.h \
    $(wildcard include/config/arm64/page/shift.h) \
    $(wildcard include/config/arm64/cont/shift.h) \
  ../include/asm-generic/getorder.h \
  ../arch/arm64/include/asm/vdso.h \

arch/arm64/kernel/vdso/vdso.lds: $(deps_arch/arm64/kernel/vdso/vdso.lds)

$(deps_arch/arm64/kernel/vdso/vdso.lds):

cmd_arch/arm64/kernel/kuser32.o := /home/chenyl6/p11-plus-s-kernel/wifi/kernel-4.14/../prebuilts/clang/host/linux-x86/clang-r383902/bin/clang -Wp,-MD,arch/arm64/kernel/.kuser32.o.d  -nostdinc -isystem /home/chenyl6/p11-plus-s-kernel/wifi/prebuilts/clang/host/linux-x86/clang-r383902/lib64/clang/11.0.1/include -I../arch/arm64/include -I./arch/arm64/include/generated  -I../include -I../drivers/misc/mediatek/include -I./include -I../arch/arm64/include/uapi -I./arch/arm64/include/generated/uapi -I../include/uapi -I./include/generated/uapi -include ../include/linux/kconfig.h -D__KERNEL__ -Qunused-arguments -mlittle-endian -DKASAN_SHADOW_SCALE_SHIFT=3 -D__ASSEMBLY__ --target=aarch64-linux-gnu --prefix=/home/chenyl6/p11-plus-s-kernel/wifi/kernel-4.14/../prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9.1/bin/ --gcc-toolchain=/home/chenyl6/p11-plus-s-kernel/wifi/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9.1 -no-integrated-as -Werror=unknown-warning-option -fno-PIE -DCONFIG_AS_LSE=1 -DKASAN_SHADOW_SCALE_SHIFT=3 -DCC_HAVE_ASM_GOTO -Wa,-gdwarf-2   -c -o arch/arm64/kernel/kuser32.o ../arch/arm64/kernel/kuser32.S

source_arch/arm64/kernel/kuser32.o := ../arch/arm64/kernel/kuser32.S

deps_arch/arm64/kernel/kuser32.o := \
  ../include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  ../arch/arm64/include/asm/unistd.h \
    $(wildcard include/config/compat.h) \
  ../arch/arm64/include/uapi/asm/unistd.h \
  ../include/asm-generic/unistd.h \
  ../include/uapi/asm-generic/unistd.h \
    $(wildcard include/config/mmu.h) \
  ../arch/arm64/include/uapi/asm/bitsperlong.h \
  ../include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  ../include/uapi/asm-generic/bitsperlong.h \
  ../include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
    $(wildcard include/config/unused/symbols.h) \

arch/arm64/kernel/kuser32.o: $(deps_arch/arm64/kernel/kuser32.o)

$(deps_arch/arm64/kernel/kuser32.o):

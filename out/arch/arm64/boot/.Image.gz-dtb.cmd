cmd_arch/arm64/boot/Image.gz-dtb := (cat arch/arm64/boot/Image.gz arch/arm64/boot/dts/mediatek/mt6785.dtb > arch/arm64/boot/Image.gz-dtb) || (rm -f arch/arm64/boot/Image.gz-dtb; false)

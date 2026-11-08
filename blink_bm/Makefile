all:
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c main.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c startup.c
	arm-none-eabi-gcc -T link.ld -nostdlib startup.o main.o -o firmware.elf
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin

flash:
	st-flash write firmware.bin 0x08000000
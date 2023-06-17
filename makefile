CC = mips-linux-gnu-gcc
LD = mips-linux-gnu-ld
CFLAGS = -march=r4300 -mips3 -O2 -nostdlib -nostartfiles -EB
LDFLAGS = -T linker.ld -Ttext 0x80043000

all: program.bin print_main_address

program.bin: program.elf
	mips-linux-gnu-objcopy -O binary program.elf program.bin

program.elf: program.o
	$(LD) $(LDFLAGS) -o program.elf program.o

program.o: program.c
	$(CC) $(CFLAGS) -c program.c -o program.o

print_main_address:
	@objdump -t program.elf

clean:
	rm -f program.o program.elf program.bin

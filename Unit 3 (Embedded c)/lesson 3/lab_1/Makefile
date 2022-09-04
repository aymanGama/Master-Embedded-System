#copyright_ayman
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)

all: learn_in_depth.bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

learn_in_depth.elf: $(ASOBJ) $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) -o learn_in_depth.elf

learn_in_depth.bin: learn_in_depth.elf
	$(CC)objcopy.exe -O binary   $< $@

.PHONY : clean
clean : 
	rm *.bin *.o *.elf 
	@echo "clean======="
#copyright_ayman
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)

all: project1_first_term.bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe  $(CFLAGS) $(INCS) -c $< -o $@

project1_first_term.elf: $(ASOBJ) $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) $(INCS) -o project1_first_term.elf -Map=map_file

project1_first_term.bin: project1_first_term.elf
	$(CC)objcopy.exe -O binary   $< $@

clean_all:
	rm *.o *.bin *.elf
#copyright_ayman
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)

all: learn_in_depth_cortex_m3.bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe  $(CFLAGS) $(INCS) -c $< -o $@

learn_in_depth_cortex_m3.elf: $(ASOBJ) $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) -o learn_in_depth_cortex_m3.elf -Map=map_file

learn_in_depth_cortex_m3.bin: learn_in_depth_cortex_m3.elf
	$(CC)objcopy.exe -O binary   $< $@


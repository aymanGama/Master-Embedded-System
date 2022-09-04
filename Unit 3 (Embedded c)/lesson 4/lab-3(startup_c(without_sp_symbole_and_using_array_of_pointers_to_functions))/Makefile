#copyright_ayman
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
project_name= unit3_lab4_cortexM4

all: $(project_name).bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe  $(CFLAGS) $(INCS) -c $< -o $@

$(project_name).elf: $(ASOBJ) $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) -o $(project_name).elf -Map=map_file
	cp $(project_name).elf   $(project_name).axf

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary   $< $@
	
	
clean_all:
	rm *.o *.bin *.elf *.axf


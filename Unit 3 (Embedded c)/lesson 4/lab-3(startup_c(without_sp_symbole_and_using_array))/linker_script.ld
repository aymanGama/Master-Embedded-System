/*LAB-2 
 ENG:Ayman_Gamal
*/
MEMORY 
{
    flash(RX)  : ORIGIN = 0X08000000, LENGTH = 128K
    sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}

SECTIONS
{
    .text : 
    {
        *(.vectors*)
        *(.text*)
        E_TEXT = . ;
    } > flash
    .data :
    {
        S_DATA = . ;
        *(.data*)
        *(.rodata*)
        . = ALIGN(4);
        E_DATA = . ;
    } >sram AT> flash
    
    .bss :
    {
        . = ALIGN(4);
        S_BSS = . ;
        *(.bss*)
        E_BSS = . ;
    } > sram
    

}
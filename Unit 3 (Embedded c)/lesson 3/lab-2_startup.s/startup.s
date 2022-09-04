/*LAB-2 
 ENG:Ayman_Gamal
*/
 .section  .vectors
 .Word   0x20001000         /* stack_top addres*/
 .Word   _reset             /*  1 reset sympole */
 .Word   Vector_handler     /*  2 NMI */
 .Word   Vector_handler     /*  3 Hard Faukt */
 .Word   Vector_handler     /*  4 MM  Fault */
 .Word   Vector_handler     /*  5 Bus fault  */
 .Word   Vector_handler     /*  6 Usage  Fault */
 .Word   Vector_handler     /*  7 RESERVED */
 .Word   Vector_handler     /*  8 RESERVED */
 .Word   Vector_handler     /*  9 RESERVED */ 
 .Word   Vector_handler     /*  10 RESERVED */
 .Word   Vector_handler     /*  11 SV call */
 .Word   Vector_handler     /*  12 Debug reserved */
 .Word   Vector_handler     /*  13 RESERVED */
 .Word   Vector_handler     /*  14 Pend SV */
 .Word   Vector_handler     /*  15 sysTick */
 .Word   Vector_handler     /*  16 IRQ0 */
 .Word   Vector_handler     /*  17 IRQ0 */
 .Word   Vector_handler     /*  18 IRQ0 */
        /*........*/
.section  .text
_reset: 
    bl main
    b .

.thumb_func
Vector_handler:
    b _reset

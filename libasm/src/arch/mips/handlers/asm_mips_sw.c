/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

int asm_mips_sw(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SW;
   return 777;
}
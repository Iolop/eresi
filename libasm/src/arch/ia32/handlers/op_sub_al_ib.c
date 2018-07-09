/**
* @file libasm/src/arch/ia32/handlers/op_sub_al_ib.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sub_al_ib" opcode="0x2c"/>
*/
int op_sub_al_ib(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SUB;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
    ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_CONTENT_FIXED, new);
  new->op[0].type = ASM_OPTYPE_REG;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_AL;
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_CONTENT_IMMEDIATEBYTE, new);
  return (new->len);
}

/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-g" "-Oz" "-Os"} } */
/* { dg-options "-march=rv32gc_xtheadmemidx" { target { rv32 } } } */

#include "xtheadmemidx-macros.h"

MV_LOAD_1_AND_2(s_int, s_char)
/* { dg-final { scan-assembler-times "th.lrb\t" 2 { target { rv32 } } } } */
MV_LOAD_1_AND_2(s_int, u_char)
/* { dg-final { scan-assembler-times "th.lrbu\t" 2 { target { rv32 } } } } */
MV_LOAD_1_AND_2(s_int, s_short)
/* { dg-final { scan-assembler-times "th.lrh\t" 2 { target { rv32 } } } } */
MV_LOAD_1_AND_2(s_int, u_short)
/* { dg-final { scan-assembler-times "th.lrhu\t" 2 { target { rv32 } } } } */
MV_LOAD_1_AND_2(s_int, s_int)
/* { dg-final { scan-assembler-times "th.lrw\t" 2 { target { rv32 } } } } */

MV_STORE_1(s_int, s_int, s_char)
/* { dg-final { scan-assembler-times "th.srb\t" 1 { target { rv32 } } } } */
MV_STORE_1(s_int, s_int, s_short)
/* { dg-final { scan-assembler-times "th.srh\t" 1 { target { rv32 } } } } */
MV_STORE_1(s_int, s_int, s_int)
/* { dg-final { scan-assembler-times "th.srw\t" 1 { target { rv32 } } } } */

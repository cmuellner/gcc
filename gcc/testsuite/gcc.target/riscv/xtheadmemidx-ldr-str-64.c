/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-g" "-Oz" "-Os"} } */
/* { dg-options "-march=rv64gc_xtheadmemidx" { target { rv64 } } } */

#include "xtheadmemidx-macros.h"

MV_LOAD_1_AND_2(s_ll, s_char)
/* { dg-final { scan-assembler-times "th.lrb\t" 2 { target { rv64 } } } } */
MV_LOAD_1_AND_2(s_ll, u_char)
/* { dg-final { scan-assembler-times "th.lrbu\t" 2 { target { rv64 } } } } */
MV_LOAD_1_AND_2(s_ll, s_short)
/* { dg-final { scan-assembler-times "th.lrh\t" 2 { target { rv64 } } } } */
MV_LOAD_1_AND_2(s_ll, u_short)
/* { dg-final { scan-assembler-times "th.lrhu\t" 2 { target { rv64 } } } } */
MV_LOAD_1_AND_2(s_ll, s_int)
/* { dg-final { scan-assembler-times "th.lrw\t" 2 { target { rv64 } } } } */
MV_LOAD_4(s_ll, s_int, u_int)
/* { dg-final { scan-assembler-times "th.lrwu\t" 1 { target { rv64 } } } } */
MV_LOAD_1_AND_2(s_ll, s_ll)
/* { dg-final { scan-assembler-times "th.lrd\t" 2 { target { rv64 } } } } */

MV_STORE_1(s_ll, s_ll, s_char)
/* { dg-final { scan-assembler-times "th.srb\t" 1 { target { rv64 } } } } */
MV_STORE_1(s_ll, s_ll, s_short)
/* { dg-final { scan-assembler-times "th.srh\t" 1 { target { rv64 } } } } */
MV_STORE_1(s_ll, s_ll, s_int)
/* { dg-final { scan-assembler-times "th.srw\t" 1 { target { rv64 } } } } */
MV_STORE_1(s_ll, s_ll, s_ll)
/* { dg-final { scan-assembler-times "th.srd\t" 1 { target { rv64 } } } } */

MV_LOAD_3(s_ll, u_int, s_char)
/* { dg-final { scan-assembler-times "th.lurb\t" 1 { target { rv64 } } } } */
MV_LOAD_3(s_ll, u_int, u_char)
/* { dg-final { scan-assembler-times "th.lurbu\t" 1 { target { rv64 } } } } */
MV_LOAD_3(s_ll, u_int, s_short)
/* { dg-final { scan-assembler-times "th.lurh\t" 1 { target { rv64 } } } } */
MV_LOAD_3(s_ll, u_int, u_short)
/* { dg-final { scan-assembler-times "th.lurhu\t" 1 { target { rv64 } } } } */
MV_LOAD_3(s_ll, u_int, s_int)
/* { dg-final { scan-assembler-times "th.lurw\t" 1 { target { rv64 } } } } */
MV_LOAD_4(s_ll, u_int, u_int)
/* { dg-final { scan-assembler-times "th.lurwu\t" 1 { target { rv64 } } } } */
MV_LOAD_3(s_ll, u_int, u_ll)
/* { dg-final { scan-assembler-times "th.lurd\t" 1 { target { rv64 } } } } */

MV_STORE_1(s_ll, u_int, s_char)
/* { dg-final { scan-assembler-times "th.surb\t" 1 { target { rv64 } } } } */
MV_STORE_1(s_ll, u_int, s_short)
/* { dg-final { scan-assembler-times "th.surh\t" 1 { target { rv64 } } } } */
MV_STORE_1(s_ll, u_int, s_int)
/* { dg-final { scan-assembler-times "th.surw\t" 1 { target { rv64 } } } } */
MV_STORE_1(s_ll, u_int, s_ll)
/* { dg-final { scan-assembler-times "th.surd\t" 1 { target { rv64 } } } } */

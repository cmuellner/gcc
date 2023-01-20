/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-g" "-Oz" "-Os"} } */
/* { dg-options "-march=rv64gc_xtheadmemidx --save-temps -O2" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_xtheadmemidx --save-temps -O2" { target { rv32 } } } */

#include "xtheadmemidx-macros.h"

/* no special function attribute required */
#define ATTR /* */

POST_LOAD(s_char, ATTR)
/* { dg-final { scan-assembler "th.lbia.*1,0" } } */
PRE_LOAD(s_char, ATTR)
/* { dg-final { scan-assembler "th.lbib.*1,0" } } */
POST_LOAD(char, ATTR)
/* { dg-final { scan-assembler "th.lbuia.*1,0" } } */
PRE_LOAD(char, ATTR)
/* { dg-final { scan-assembler "th.lbuib.*1,0" } } */
POST_LOAD(short, ATTR)
/* { dg-final { scan-assembler "th.lhia.*2,0" } } */
PRE_LOAD(short, ATTR)
/* { dg-final { scan-assembler "th.lhib.*2,0" } } */
POST_LOAD(u_short, ATTR)
/* { dg-final { scan-assembler "th.lhuia.*2,0" } } */
PRE_LOAD(u_short, ATTR)
/* { dg-final { scan-assembler "th.lhuib.*2,0" } } */

POST_LOAD(int, ATTR)
/* { dg-final { scan-assembler "th.lwia.*4,0" } } */
PRE_LOAD(int, ATTR)
/* { dg-final { scan-assembler "th.lwib.*4,0" } } */
void int_post_load_lwuia (void* p) 
{  
  extern void fint2 (int*,u_ll);
  u_int *q = (u_int*)p;
  u_ll x = *q++;
  fint2 (q, x);
}
/* { dg-final { scan-assembler "th.lwuia.*4,0" { target { rv64 } } } } */
void int_pre_load_lwuib (void* p) 
{  
  extern void fint2 (int*,u_ll);
  u_int *q = (u_int*)p;
  u_ll x = *++q;
  fint2 (q, x);
}
/* { dg-final { scan-assembler "th.lwuib.*4,0" { target { rv64 } } } } */

POST_LOAD(s_ll, ATTR)
/* { dg-final { scan-assembler "th.ldia.*8,0" { target { rv64 } } } } */
PRE_LOAD(s_ll, ATTR)
/* { dg-final { scan-assembler "th.ldib.*8,0" { target { rv64 } } } } */

POST_STORE(char, ATTR)
/* { dg-final { scan-assembler "th.sbia.*1,0" } } */
PRE_STORE(char, ATTR)
/* { dg-final { scan-assembler "th.sbib.*1,0" } } */
POST_STORE(short, ATTR)
/* { dg-final { scan-assembler "th.shia.*2,0" } } */
PRE_STORE(short, ATTR)
/* { dg-final { scan-assembler "th.shib.*2,0" } } */
POST_STORE(int, ATTR)
/* { dg-final { scan-assembler "th.swia.*4,0" } } */
PRE_STORE(int, ATTR)
/* { dg-final { scan-assembler "th.swib.*4,0" } } */
POST_STORE(s_ll, ATTR)
/* { dg-final { scan-assembler "th.sdia.*8,0" { target { rv64 } } } } */
PRE_STORE(s_ll, ATTR)
/* { dg-final { scan-assembler "th.sdib.*8,0" { target { rv64 } } } } */

/* { dg-final { scan-assembler-not "\taddi" { target { rv64 } } } } */
/* { dg-final { cleanup-saved-temps } } */

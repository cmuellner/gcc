/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-g" "-Oz" "-Os"} } */
/* { dg-options "-march=rv64gc_xtheadfmemidx --save-temps -O2" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_xtheadfmemidx --save-temps -O2" { target { rv32 } } } */

float func_f(float *a, int b)
{
    return a[b];
}
/* { dg-final { scan-assembler "th.flrw" } } */

double func_d(double *a, int b)
{
    return a[b];
}
/* { dg-final { scan-assembler "th.flrd" } } */

float func_sf(float *a, int b, float c)
{
    a[b] = c;
    return a[b];
}
/* { dg-final { scan-assembler "th.fsrw" } } */

double func_sd(double *a, int b, double c)
{
    a[b] = c;
    return a[b];
}
/* { dg-final { scan-assembler "th.fsrd" } } */

float func_uf(float *a, unsigned int b)
{
    return a[b];
}
/* { dg-final { scan-assembler "th.flurw" { target { rv64 } } } } */

double func_ud(double *a, unsigned int b)
{
    return a[b];
}
/* { dg-final { scan-assembler "th.flurd" { target { rv64 } } } } */

float func_usf(float *a, unsigned int b, float c)
{
    a[b] = c;
    return a[b];
}
/* { dg-final { scan-assembler "th.fsurw" { target { rv64 } } } } */

double func_usd(double *a, unsigned int b, double c)
{
    a[b] = c;
    return a[b];
}
/* { dg-final { scan-assembler "th.fsurd" { target { rv64 } } } } */

/* { dg-final { cleanup-saved-temps } } */

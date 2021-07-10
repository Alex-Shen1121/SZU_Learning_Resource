/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

//1
int test_bitXor(int x, int y)
{
  return x^y;
}
int test_tmin(void) {
  return 0x80000000;
}
//2
int test_isTmax(int x) {
    return x == 0x7FFFFFFF;
}
int test_allOddBits(int x) {
  int i;
  for (i = 1; i < 32; i+=2)
      if ((x & (1<<i)) == 0)
   return 0;
  return 1;
}
int test_negate(int x) {
  return -x;
}
//3
int test_isAsciiDigit(int x) {
  return (0x30 <= x) && (x <= 0x39);
}
int test_conditional(int x, int y, int z)
{
  return x?y:z;
}
int test_isLessOrEqual(int x, int y)
{
  return x <= y;
}
//4
int test_logicalNeg(int x)
{
  return !x;
}
int test_howManyBits(int x) {
    unsigned int a, cnt;
    x = x<0 ? -x-1 : x;
    a = (unsigned int)x;
    for (cnt=0; a; a>>=1, cnt++)
        ;
    return (int)(cnt + 1);
}
//float
unsigned test_float_twice(unsigned uf) {
  float f = u2f(uf);
  float tf = 2*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}
unsigned test_float_i2f(int x) {
  float f = (float) x;
  return f2u(f);
}
int test_float_f2i(unsigned uf) {
  float f = u2f(uf);
  int x = (int) f;
  return x;
}

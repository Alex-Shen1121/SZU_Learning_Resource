/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
	return ~(~(x & ~y) & ~(y & ~x));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
	return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x)
{
	int i = x + 1; //Tmin,1000...
	x = x + i;	   //-1,1111...
	x = ~x;		   //0,0000...
	i = !i;		   //exclude x=0xffff...
	x = x + i;	   //exclude x=0xffff...
	return !x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
	// return !(~x & 0xaaaaaaaa);
	int temp = (170 << 24) + (170 << 16) + (170 << 8) + 170;
	x = x & temp;
	return !(x ^ temp);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
	return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
	return (!((x + (~0x30 + 1)) >> 31)) & ((x + (~0x3a + 1)) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
	// x = (x >> 31) << 31;
	// return ((!x + ~1 + 1) & y) | ((~!x + 1) & z);
	int flag = !x + ~1 + 1;
	return (flag & y) | (~flag & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
	int y_minus_x = y + ~x + 1;		//y-x
	int Sign = y_minus_x >> 31 & 1; //y-x的符号
	int leftBit = 1 << 31;			//最大位为1的32位有符号数
	int x_sign = x & leftBit;		//x的符号
	int y_sign = y & leftBit;		//y的符号
	int bitXor = x_sign ^ y_sign;	//x和y符号相同标志位，相同为0不同为1
	bitXor = (bitXor >> 31) & 1;	//符号相同标志位格式化为0或1
	return ((!bitXor) & (!Sign)) | (bitXor & (x_sign >> 31));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x)
{
	return ((x | (~x + 1)) >> 31) + 1;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
	int b16, b8, b4, b2, b1, b0;
	int sign = x >> 31;
	x = (sign & ~x) | (~sign & x);
	//如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）
	// 不断缩小范围
	b16 = !!(x >> 16) << 4; //高十六位是否有1
	x = x >> b16;			//如果有（至少需要16位），则将原数右移16位
	b8 = !!(x >> 8) << 3;	//剩余位高8位是否有1
	x = x >> b8;			//如果有（至少需要16+8=24位），则右移8位
	b4 = !!(x >> 4) << 2;	//同理
	x = x >> b4;
	b2 = !!(x >> 2) << 1;
	x = x >> b2;
	b1 = !!(x >> 1);
	x = x >> b1;
	b0 = x;
	return b16 + b8 + b4 + b2 + b1 + b0 + 1; //+1表示加上符号位
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{
	// 提取各个字段
	unsigned s = uf & (0x80 << 24);
	unsigned exp = uf & ((0x7f << 24) + (0x80 << 16));
	unsigned frac = uf & ((0x7f << 16) + (0xff << 8) + 0xff);

	// 正数
	if (!exp)
	{
		frac = frac << 1;
		/*将frac左移一位，若尾数部分第一位为0，左移前后均为非规格化数，
尾数左移一位就相当于乘2;若尾数部分第一位为1，左移前为非规格化数，
左移后阶码部分由00000000变为00000001，阶码由1-127=-126(1-Bias)
变为e-127=1-127=-126(e-Bias),所得数为规格化数，尾数被解释为1+f,
相当于尾数乘2，阶码不变*/
	}
	// 负数
	else if (exp ^ ((0x7f << 24) + (0x80 << 16))) //如果阶码部分不为全1
	{
		exp += (0x80 << 16);						//阶码加1，对于规格化数，相当于乘2
		if (!(exp ^ ((0x7f << 24) + (0x80 << 16)))) //如果加1后，阶码为全1，将尾数位全置0，返回值即是无穷大
		{
			frac = 0;
		}
	}
	/*对于阶码为在本身为全1的NaN，本函数没有对其进行操作，返回原数据，满足关卡要求*/
	// exp == 255 返回原始值
	return s | exp | frac; //将符号位，阶码位，尾数位通过按位异或结合起来
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x)
{
	int sign = x >> 31 & 1;
	int i;
	int exp;
	int frac;
	int delta;
	int mask;
	if (x == 0)
		return x;
	// x为最小整型数
	else if (x == 1 << 31)
		exp = 158;
	else
	{
		if (sign)
			x = -x;
		i = 30;
		while (!(x >> i))
			i--; //小数点偏移位数
		exp = i + 127;
		x = x << (31 - i);
		mask = 0x7f << 16 | 0xff << 8 | 0xff; // 0x7fffff
		frac = mask & (x >> 8);
		//得到23位的小数域

		x = x & 0xff;								   //高8位
		delta = x > 128 || ((x == 128) && (frac & 1)); //向偶数舍入

		frac += delta;
		if (frac >> 23)
		{
			frac &= mask; //处理溢出情况
			exp += 1;
		}
	}
	return (sign << 31) | (exp << 23) | frac;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf)
{
	// 提取各个字段
	unsigned s = uf & (0x80 << 24);
	unsigned exp = (uf & ((0x7f << 24) + (0x80 << 16))) >> 23;
	unsigned frac = (uf & ((0x7f << 16) + (0xff << 8) + 0xff)) | (1 << 23);

	// 全为0，表示0，或者是小于1的非规格化浮点数，返回0
	if ((!exp) || exp < 127)
	{
		return 0;
	}
	// 溢出int的范围则返回1
	if (exp >= 31 + 127)
	{
		return 1 << 31;
	}

	// 补码转化
	frac = frac >> (23 - (exp - 127));
	unsigned mask1 = (!s) + (~1) + 1;
	unsigned mask2 = ~(!s) + 1;
	frac = (mask1 & ((~frac) + 1)) | (mask2 & frac);

	return s | frac;
}

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
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {

  return ~((~x)|(~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int a = n << 3; // n*8 because one byte is 8 bits
  int b = x >> a; // shift n*8 bits to the right 
  return b&0xFF;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
  int num_arithshift = x >> n; // first, shift x by arithmetic shift
  // now, make logical shift by using arithmetic shift and some bits like (111...1 , 011...1, 0011....1, 00011...1  ...)
  int num_bit = ((0x1<<31)>>31) << n; // make successive (32-n) bits by 1, n bits by 0 like (111...100..000) 
  int subtract_from_32 = ~ ((~32+0x01) + n) + 1; // it means (subtract_from_32 = 32 - n)
  num_bit = ~ ((~ num_bit) << subtract_from_32); // this num_bit consists of successive n bits by 0, (32-n) bits by 1 like (00..00111..111) 
  return num_arithshift & num_bit;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // first make mask like 0x01010101, and number of 1's in each 8 bits accumulate at 1,9,17,25 bit location from right end, lastly add each accumulation(1,9,17,25)
  int mask = 0x01 + ((0x01) << 8) + ((0x01) << 16) + ((0x01) << 24);
  int sum = mask & x;
  x = x >> 1;
  sum = sum + (mask & x);
  x = x >> 1;
  sum = sum + (mask & x);
  x = x >> 1;
  sum = sum + (mask & x);
  x = x >> 1;
  sum = sum + (mask & x);
  x = x >> 1;
  sum = sum + (mask & x);
  x = x >> 1;
  sum = sum + (mask & x);
  x = x >> 1;
  sum = sum + (mask & x);

  return (sum & 0xF) + ((sum >> 8) & 0xF) + ((sum >> 16) & 0xF) + ((sum >> 24) & 0xF);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {

  return ~((( (~x + 1) >> 31 ) & 1 ) | ((x >> 31) & 1 ))+ 2; 
  // in case x=0, Sign bit of (~x+1) is not 1 and it has '0' sign bit, 
  // but in case x>0, Sign bit of (~x+1) is 1. and in case x<0, sign bit is 1
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {  //
  // If bits of x from n to 32 (from left end) consist of all 1 or all 0, function 'fitsBits' will return 1.
  int num_shift = x >> (n+(~1)+1);  // 
  int a = (!(!(num_shift ^ 0))) & (!(!(num_shift ^ ((0x1<<31)>>31)))); // If bits of num_shift consist of only 1 or only 0, integer 'a' will be 0
                                                            // Else, integer 'a' will be 1
  return ~a+2; // if a is 0, then ~a+2 is 1. and, if a is 1, then ~a+2 is 0
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  // when sign bit of x is 0 (x>0), throw down the demical point after dividing x. so, num_add is not needed.
  // when sign bit of x is 1 (x<0) and -x is not the multiple of 2^n, num_add is needed. (num_add = 1)
  int sign_bit = (x>>31) & 1;
  int check_bit = ~ (((0x1<<31)>>31) << n); // check_bit consists of (32-n) consecutive 0 bits and (n) consecutive 1 bits.
  int num_add = sign_bit & !(!(check_bit & x)); // if (check_bit & x) is 0, -x is the multiple of 2^n and if (check_bit & x) is not 0, -x is not the multilple of 2^n.
  return (x >> n) + num_add;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  // considering the difference between 0 and positive number
  int sign_bit = (x>>31) & 1; // sign_bit is sign bit of x.
  int change_bit = ~sign_bit + 2; // if sign_bit is 0, then change_bit is 1 and if sign_bit is 1, then change_bit is 0
  int y = ~x + change_bit; // now, if x>0, sign bit of y is 1 and if x<=0, sign bit of y is 0.

  return (y>>31) & 1;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // Because y-x can be occurred overflow, y - x is impossible. so, I compute y/2 - x/2 
  int a = 0;
  int b = 0;
  int c = 0;
  int num_subtract2=0;
  int num_subtract1 = (~ (x & 1) + 1) + (y & 1); // first bit from right of y - first bit from right of x
  x = x >> 1; // x/2
  y = y >> 1; // y/2
  num_subtract2 = ((~x + 1) + y); // y/2 - x/2
  a = ~ ((num_subtract2 >> 31) & 1) + 2; // if sign bit of y/2 - x/2 is 0 (y/2-x/2 >= 0), then a will be 1 , and if sign bit of y/2 - x/2 is 1(y/2-x/2 < 0), then a will be 0
  b = !(!(num_subtract2)); //if y/2 - x/2 = 0, then b will be 0, and if y/2 - x/2 != 0, then b will be 1.
  c = ~ ((num_subtract1 >> 31) & 1) + 2; // if first bit from right of (y - x) >= 0, then c will be 1, and if first bit from right of (y - x) < 0, then c will be 0

  return a & ((a & b) | (a & c)); // at first 'a' means if x/2 > y/2, then a will be 0, so return 0 // second (a&b) means if y/2 > x/2, then (a&b) will be 1, so return 1 // third (a&c) works when y/2 = x/2 
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  // I should find the left most bit 1. and that position number from the right is what this function should return.
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0; // initialization
  a = !(!(x >> 16)); // first, seperate 32 bits to a pair of 16bits. and, if front 16 bits is not 0(including 1), then a will be 1
  x = x >> (a << 4); // when a is 1, Because front 16 bits has 1, all bits should transfer 16 bits to the right. when a is 0, all bits need not transfer
  // now, investigate in 0 to 16 bit from right.
  b = !(!(x >> 8)); // second, seperate 16 bits to a pair of 8bits. and, if front 8 bits is not 0(including 1), then b will be 1.
  x = x >> (b << 3); // when b is 1, Because front 8 bits has 1, all bits should transfer 8 bits to the right. when a is 0, all bits need not transfer
  // now, investigate in 0 to 8 bit from right.
  c = !(!(x >> 4)); // do the same process like above.
  x = x >> (c << 2);

  d = !(!(x >> 2));
  x = x >> (d << 1);

  e = !(!(x >> 1));

  return (a<<4) + (b<<3) + (c<<2) + (d<<1) + e; // for example (a,b,c,d,e) = (1,1,1,1,0) means leading 1's(left most bit) exist at the position of (16+8+4+2 = 30).
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  unsigned int a = (uf << 1);

  if ( (a>0xFF000000) && (a<=0xFFFFFFFF) ){  // when argument is NaN.
    return uf;
  }
  else{
    return uf + 0x80000000; // just change the sign bit of floating point.
  }
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
unsigned float_i2f(int x) {
  //
  unsigned int sign_bit = 0;
  unsigned int E = 0;
  unsigned int fraction = 0;
  unsigned int carry = 0;
  unsigned int expo = 0;
  unsigned int n = 0;
  unsigned int y = 0;

 // sign_bit part

  if ( x & 0x80000000 ){
    sign_bit = 1;
    x = ~x+1;
  }

 // E : exponential part
  if (x==0){
    return 0;
  }

  y = x; // x doesn't change because of other operations.
  while (((y>>31) & 1) != 1){ // check the position where the leading 1's (left most bit) is located.
    y = y<<1;
    n = n + 1;
  }
  E = 31 - n;
  expo = E + 127;

 // fractional part
  if (((x<<n) & 0x1FF) >= 0x180){ // considering rounding
    carry = 1;
  }
  if (((x<<n) & 0xFF) > 0x80){ // considering rounding
    carry = 1;
  }
  
  fraction = (((x<<n) >> 8) & 0x7FFFFF) + carry;

  return (sign_bit<<31) + (expo << 23) + fraction;

}
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
unsigned float_twice(unsigned uf) {
  
  unsigned int sign_bit = 0;
  unsigned int expo = 0;
  unsigned int fraction = 0;
  unsigned int a = (uf << 1);

  sign_bit = (uf >> 31) & 1;
  expo = (uf>>23) & 0xFF;
  fraction = uf & 0x7FFFFF;

  if ( ((a>=0xFF000000) && (a<=0xFFFFFFFF))){  // when argument is NaN.
    return uf;
  }

  if ( expo != 0 ){  // when exponential part is not 0
    expo = expo + 1;
  }

  else{ // when exponential part is 0
    fraction = fraction << 1; 
  }

  return (sign_bit << 31) + (expo << 23) + fraction;

}

// https://leetcode.com/problems/number-complement/
class Solution
{
public:
    int findComplement(int num)
    {
        /*
        * First we need to find the Bit Length, i.e. the number
        * of bits in the binary representation of the integer
        * a very easy way would be to keep right shifting the number
        * till it becomes 0
        * 5 --> 101
        * 101 >> 1 = 10
        * 10 >> 1 = 1
        * 1 >> 1 = 0
        * The number of iterations is the number of bits.
        * But there is a much faster way to do this.
        * Whenever you right shift a number, you are essentially
        * dividing it by 2. (Similarly, left shift means multiplying by 2)
        * So we're just finding out how many times do we need to divide the
        * number until we reach 0. This is essentially the definition of
        * finding the log2() of a number repeatedly + 1
        * (Because log2 of a number is basically the number of times you
        * need to divide it by 2 to reach 1 - and our goal is to reach 0, 
        * so we add an extra 1).
        */
        int bitLength = (int)log2(num) + 1;
        /*
        * Now we want to make a bitmask
        * Let's say we have 5, which is represented as
        * 101
        * if we right shift 1, bitLength number of times, i.e. 1 << bitLength
        * we get 1000
        * and if we subtract 1 from this, we get -> 111
        * Now 111 can be used as a bitmask
        * We use unsigned int to avoid sign issues
        */
        unsigned int bitmask;
        if (bitLength < 31)
        {
            // you can't right shift 31 times, or it causes overflow
            // so this only works for bitLengths < 31
            bitmask = (1 << bitLength) - 1;
        }
        else
        {
            // if the number of bits is 31, i.e. all bits (other than sign bit)
            // are used to represent the number
            // We create the bitmask by first setting all bits to 1
            // then right shifting it by 1 position
            bitmask = 0xffffffff;
            bitmask = bitmask >> 1;
        }
        /*
        * The easiest way to invert a bit is to XOR it with 1
        * So we XOR the number with its bitMask that we just found
        */
        return num ^ bitmask;
    }
};
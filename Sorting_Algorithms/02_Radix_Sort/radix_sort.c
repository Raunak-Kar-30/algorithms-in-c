// Radix sorting algorithm uses the bit manipulation techniques to sort the keys of a given data (or just sort the value if the keys are the data)
// We take advantage of the fact that there are only 2 bits in the binary representation of the numbers (keys).
// 
// Process : What we do is that we try to compare the nth bit of an m bit number (key - represented in binary), and that nth bit with the nth
// bit of all the keys. Since there are only 2 possible value of a bit, the number of comparisons for each digit can only be once.
// We then rearrange the numbers based on their nth bit, such that all numbers with nth bit set to 0 occur before all number with nth bit set to 1.
//
// In case of Exchange Radix Sort : 
// We start doing this process with the Most Significant Bit - and re-arranging every number such that all number with MSB 0 appear before
// with all numbers with MSB 0. 
// We keep doing the process for every bits from MSB -> LSB for every number. At the end of LSB comparisons we get the full sorted array.

// Includes
#include <stdio.h>
#include <stdint.h>

// Function declarations
void radix_ex_sort(int *array, int len);
uint32_t bits(uint32_t key, int bfr, int nb)

// Main function

// Radix Exchange Sort : b is the number of bits for the representation of the keys
// So for eg : if key is an integer value, it must use 32 bits, we write 31 to b
void radix_ex_sort(int *array, int left, int right, int b)
{
    
}

// Return l number of bits starting from the kth bit
uint32_t bits(uint32_t key, int k, int l)
{
    // 0UL means 0000 0000, so ~0UL means 1111 1111. Now bit shift it by l (lets say 2) number of bits gives us 1111 1100.
    // ~ (1111 1100) = 0000 0011 which ultimately gives us the appropriate bit masks for l number of bits.
    // We then bit-shift the key by k, to move key by k bits to the right, which sends kth bit to the 0th bit position.
    // Ultimately, this expression then provides us with l number of bit (since l bits are masked by 1), starting from the kth position
    // (since the kth bit has now been shifted to the 0th postion)
    return ((key >> k) & ~(~0UL << l));
}
#include <stdio.h>
#include <conio.h>


int extract_bit(int number, int offset, int length)
{
    unsigned int num2 = (number >> (offset - 1));
    unsigned int mask = (1 << length) - 1;
    return (num2 & mask);
}

int extract_bit2(int number, int offset, int length)
{
    int maskbit = ~(0xFFFFFFFF << length);

    number >>= (offset - 1);
    number &= maskbit;

    return number;
}

int modify_bit(int number, int offset, int value)
{
    unsigned int mask0 = ((unsigned int)1 << (offset - 1));
    unsigned int mask1 = (unsigned int)0xFFFFFFFF - mask0;
    unsigned int mask2 = (value != 0) << (offset - 1);
    unsigned int num2 = (number & mask1);
    return (num2 | mask2);
}

int modify_bit2(int number, int offset, int value)
{
    int maskbit = ~(!value << (offset - 1));
    return (number & maskbit);
}

int main()
{
    int value = 171; // 10101011
    
    value = extract_bit(value, 1, 2); // output: 3
    print("%d", value);

    value = modify_bit(value, 2, 0); // output: 169
    print("%d", value);

    return 0;
}

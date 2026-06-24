#include <stdio.h>

unsigned char modifyRegister(unsigned char reg)
{
    reg |= (1 << 2);      // Set bit 2
    reg &= ~(1 << 5);     // Clear bit 5
    reg ^= (1 << 0);      // Toggle bit 0

    return reg;
}

int main()
{
    unsigned char reg = 0x20;  // 0010 0000
    reg = modifyRegister(reg);

    printf("Modified Register = 0x%X\n", reg);

    return 0;
}
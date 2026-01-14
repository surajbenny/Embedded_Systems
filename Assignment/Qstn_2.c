unsigned char modifyRegister(unsigned char reg)
{
    reg = reg | (1 << 2);     // set bit 2
    reg = reg & ~(1 << 5);    // clear bit 5
    reg = reg ^ (1 << 0);     // toggle bit 0

    return reg;
}

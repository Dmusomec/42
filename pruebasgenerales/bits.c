#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 7;

    while (i > -1)
    {
        if ((octet >> i) & 1)
            write (1, "1", 1);
        else
            write (1, "0", 1);
        i--;
    }
    write (1, "\n", 1);
}

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char reversed = 0;
    int i = 8;
    while (i--)
    {
        reversed = (reversed << 1) | (octet & 1);
        octet >>= 1;
    }
    return reversed;
}

unsigned char swap_bits(unsigned char octet)
{
    return (octet << 4) | (octet >> 4);
}
int is_power_of_2(unsigned int n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}

int main()
{
    unsigned char bytes = 0b01000001;
    print_bits(bytes);
    print_bits(reverse_bits(bytes));
    print_bits(swap_bits(bytes));
    
    return (0);
}
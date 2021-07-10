#include <stdio.h>
void print_bin(int n)
{
    int l = sizeof(n) * 8; //总位数。
    int i;
    if (i == 0)
    {
        printf("0");
        return;
    }
    for (i = l - 1; i >= 0; i--) //略去高位0.
    {
        if (n & (1 << i))
            break;
    }

    for (; i >= 0; i--)
        printf("%d", (n & (1 << i)) != 0);
    printf("\n");
}
int main()
{
    int a = 5;
    // print_bin(a);
    // print_bin(!a);
    int x = 0x7f << 16 | 0xff << 8 | 0xff;
    printf("%d\n", 0xff);
    printf("%d\n", 600 & 0xff);
    return 0;
}
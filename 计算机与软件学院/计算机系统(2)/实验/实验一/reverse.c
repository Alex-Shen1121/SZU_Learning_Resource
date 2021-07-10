#include <stdio.h>
#include <string.h>
#include "reverse.h"

int reverse(char *str)
{
    int i;
    int len;
    char c;
    len = strlen(str);
    for (i = 0; i < len / 2; i++)
    {
        c = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = c;
    }
}

int main(void)
{
    char str[1024];
    printf("Give me a word to reverse:\n");
    scanf("%s", &str);
    reverse(str);
    printf("REVERSED:%s", str);
}
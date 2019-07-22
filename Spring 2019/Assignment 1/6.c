/*
    JTSK-320112
    a1-p6.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned char c;
    scanf("%c", &c);
    unsigned int mask = 128;
    /*10000000 in binary representation
    to print results in 8 bits*/
    printf("The decimal representation is: %d\n",c);
    printf("The binary representation is: ");
    while(mask>0)
    {
        /*bit if 1 is found in one of the bits,
        the mask result will be larger than 1.
        otherwise, the result will be zero.*/
        if((c&mask)==0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        mask >>= 1;
        //rightshift 1 position to update mask value
    }
    printf("\n");
    return 0;
}

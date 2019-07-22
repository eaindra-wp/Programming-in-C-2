/*
    JTSK-320112
    a1-p7.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
char set3bits(unsigned char c,int x,int y,int z)
{
    unsigned char r;
    int d=1<<x, e=1<<y, f=1<<z;
    /*leftshift 1 to the inputs' positions,
    to compare with the input char*/
    r = c|d|e|f;
    /*or bitwise operation is used to set 1s
    at input locations*/
    return r;
}
int main()
{
    unsigned char d;
    scanf("%c", &d);
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    /*10000000 in binary representation
    to print results in 8 bits*/
    unsigned int mask1=128, mask2=128;
    printf("The decimal representation is: %d\n", d);
    printf("The binary representation is: ");
    while(mask1>0)
    {
        if((d&mask1)==0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        mask1 >>= 1;
        //rightshift 1 to update mask value
    }
    printf("\n");
    printf("After setting the bits: ");
    /*print the new result with 1s being
    replaced at input bit positions*/
    while(mask2>0)
    {
        if((set3bits(d,a,b,c)&mask2)==0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        mask2 >>= 1;
        //rightshift 1 position to update mask value
    }
    printf("\n");
    return 0;
}

/*
    JTSK-320112
    a1-p5.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char c,f;
    scanf("%c", &c);
    //get char input
    f = c;
    //assign the input to new char variable
    printf("The decimal representation is: %d\n", c);
    printf("The backwards binary representation is: ");
    //to print binary result in backward position
    while(f>0)
    {
        //and comparison with bitmask 1
        if((f&1)==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        f >>= 1;
       //rightshift 1 position to update input value
    }
    printf("\n");
    return 0;
}

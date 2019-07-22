/*
    JTSK-320112
    a1-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#define bit(c) {c=c&00000001;}
//check the least significant bit
int main()
{
    unsigned char c;
    scanf("%c", &c);
    printf("The decimal representation is: %d\n", c);
    bit(c);
    //call the macro before printing
    printf("The least significant bit is: %d\n", c);
}

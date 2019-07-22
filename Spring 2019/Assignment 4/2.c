/*
    JTSK-320112
    a4-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//change all to upper case
void upper(char* c)
{
    while(*c!='\0')
    {
        printf("%c",toupper(*c));
        c++;
    }
}
//change all to lower case
void lower(char *c)
{
    while(*c!='\0')
    {
        printf("%c",tolower(*c));
        c++;
    }
}
/*change upper to lower,and
lower to upper*/
void swap(char *c)
{
    while(*c!='\0')
    {
        if(isupper(*c))
            printf("%c",tolower(*c));
        else if (islower(*c))
            printf("%c",toupper(*c));
        else
            printf("%c",*c);
        c++;
    }
}
//quit function
void quit(char *c)
{
    exit(0);
    return;
}
int main()
{
    char c[100];
    fgets(c,sizeof(c),stdin);
    //read the string
    int i;
    /*call function pointers in an array,
    functions listed from 0 to 3*/
    void(*func_arr[4])(char*)
                            ={upper,lower,swap,quit};
    //get input to choose function
    while(1)
    {
        scanf("%d",&i);
        func_arr[i -1](c);
    }
}

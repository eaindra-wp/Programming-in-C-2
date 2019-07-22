/*
    JTSK-320112
    a5-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct stack *st;
    st = (struct stack*)malloc(sizeof(struct stack));
    //dynamically allocate the linked list
    if  (st==NULL)
    {
        printf("Allocation error\n");
        exit(1);
    }
    //set the count be zero
    st->count = 0;
    int n,r,c;
    scanf("%d",&n);
    c = n;
    while(c!=0)
    {
        r = c%2;
        c = c/2;
        push(r,st);
    }
    pop(n,st);
    return 0;
}

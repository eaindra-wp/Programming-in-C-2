/*
    JTSK-320112
    a5-p1.c
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
    char c;
    int n;
    while(1)
    {
        /*the input will be accepted
        as long as the program is true*/
        scanf("%c",&c);
        getchar();
        switch(c)
        {
        case 's':
            scanf("%d",&n);
            getchar();
            push(n,st);
            break;
        case 'p':
            st = pop(st);
            break;
        case 'e':
            empty(st);
            break;
        case 'q':
            printf("Quit\n");
            return 0;
            break;
        }
    }
}

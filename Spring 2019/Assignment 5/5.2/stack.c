/*
    JTSK-320112
    a5-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
//check whether the list is full
int isFull(struct stack *st)
{
    if(st->count >= 100)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//check whether the list is empty
int isEmpty(struct stack *st)
{
    if(st->count <= 0)
        return 1;
    else
        return 0;
}
//popping out one element
void pop(int n,struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The binary representation of %d is ",n);
        while(st->count != 0)
        {
            st->count--;
            printf("%d",st->array[st->count]);
        }
        printf(".\n");
    }
}
/*pushing the elements in reverse
so bits will be printed in the correct
order.*/
void push(int x,struct stack *st)
{
    if(isFull(st))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->array[st->count] = x;
        st->count++;
    }
}

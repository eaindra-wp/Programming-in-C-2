/*
    JTSK-320112
    a5-p1.c
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
    if(st->count >= 12)
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
struct stack *pop(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Popping Stack Underflow\n");
    }
    else
    {
        st->count--;
        printf("Popping %d\n",st->array[st->count]);
    }
    return st;
}
//pushing one element
void push(int x,struct stack *st)
{
    if(isFull(st))
    {
        printf("Pushing Stack Overflow\n");
    }
    else
    {
        st->array[st->count] = x;
        st->count++;
        printf("Pushing %d\n",x);
    }
}
//emptying the whole list
void empty(struct stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        //calling the string repeatedly
        printf("Emptying Stack ");
        while(st->count != 0)
        {
            st->count--;
            printf("%d ",st->array[st->count]);
        }
        printf("\n");
    }
}


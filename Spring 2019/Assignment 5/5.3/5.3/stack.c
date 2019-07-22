/*
    JTSK-320112
    a5-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "stack.h"
//check whether the list is full
int isFull(struct stack *st)
{
    if(st->count >= 30)
        return 1;
    else
        return 0;
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
char *pop(struct stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
    }
    char *cmp;
    cmp=(char*)malloc(sizeof(char)
                      *strlen(st->array[st->count-1].word));
    strcpy(cmp,st->array[st->count-1].word);
    st->count--;
    return cmp;
    strcpy(st->array[st->count-1].word,"");
    free(cmp);
}
//push words into the list
void push(char *x,struct stack *st)
{
    if(isFull(st))
    {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(st->array[st->count].word,x);
    st->count++;
}

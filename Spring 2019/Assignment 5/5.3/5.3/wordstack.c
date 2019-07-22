/*
    JTSK-320112
    a5-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
int main()
{
    struct stack *st;
    st=(struct stack*)malloc(sizeof(struct stack));
    //allocate struct
    st->count = 0;
    //empty all char arrays in the list
    for(int i=0; i<30; i++)
    {
        strcpy(st->array[i].word, "");
    }
    st->count = 0;
    if (st==NULL)
    {
        printf("Allocation error\n");
        exit(1);
    }
    char sent[900];
    while(1)
    {
        fgets(sent,sizeof(sent),stdin);
        sent[strlen(sent)-1] = '\0';
        if(strcmp(sent,"exit\0")==0)
        {
            free(st);
            return 0;
        }
        else
        {
            char sep[30];
            strcpy(sep,"");
            //separator to be pushed
            for(int i=0; i<strlen(sent); i++)
            {
                if(sent[i] == ' ')
                {
                    push(sep,st);
                    strcpy(sep,"");
                    /*the word will be pushed to
                    the stack*/
                }
                else
                {
                    char *ch=(char*)malloc(sizeof(sent[i]));
                    *ch = sent[i];
                    strcat(sep,ch);
                    //concat the char of the word
                    free(ch);
                    //push the last word
                    if(i==strlen(sent)-1)
                    {
                        push(sep,st);
                        strcpy(sep,"");
                    }
                }
            }
        }
        char cmp[900];
        strcpy(cmp,"");
        //pop words from the stack
        while(!isEmpty(st))
        {
            strcat(cmp,pop(st));
            strcat(cmp," ");
        }
        cmp[strlen(cmp)-1] = '\0';
        if(strcmp(sent,cmp)==0)
        {
            printf("The sentence is palindromic by words!\n");
        }
        else
        {
            printf("The sentence is not palindromic by words!\n");
        }
    }
}

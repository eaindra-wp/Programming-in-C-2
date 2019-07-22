/*
    JTSK-320112
    a3-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct list * mylist = NULL;
    char c;
    int i;
    //as long as the program is true
    while(1)
    {
        scanf("%c",&c);
        /*different functions will work
        according to inputs*/
        switch(c)
        {
            case 'b':
                scanf("%d",&i);
                mylist = push_front(mylist,i);
            break;
            case 'a':
                scanf("%d",&i);
                mylist = push_back(mylist,i);
            break;
            case 'r':
                mylist= remove_front(mylist);
            break;
            case 'p':
                printlist(mylist);
            break;
            case 'q':
                freelist(mylist);
                return 0;
            break;
        }
        getchar();
    }
}

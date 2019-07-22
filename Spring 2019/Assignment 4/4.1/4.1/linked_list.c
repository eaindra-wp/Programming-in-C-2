/*
    JTSK-320112
    a3-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//adding to the back of linked list
struct list* push_back(struct list* mylist,
                       int value)
{
    struct list *cursor, *nl;
    cursor=mylist;
    /*copy struct so that
    it won't clash the original list*/
    //allocate a new list
    nl=(struct list *) malloc(sizeof(struct list));
    if (nl==NULL)
    {
        printf("Error allocating memory\n");
        return mylist;
    }
    nl->info=value;
    nl->next=NULL;
    //pushing values
    if(mylist==NULL)
        return nl;
    while(cursor->next!=NULL)
    {
        cursor=cursor->next;
    }
    cursor->next=nl;
    return mylist;
}
//add an element to the front of list
struct list* push_front(struct list* mylist, int value)
{
    struct list *nl;
    nl = (struct list*)malloc(sizeof(struct list));
    //allocate the new list to push
    if(nl==NULL)
    {
        printf("Error allocating memory\n");
        return mylist;
    }
    //push values
    nl->info=value;
    nl->next=mylist;
    return nl;
}
//freeing the linked list
void freelist(struct list* mylist)
{
    struct list *nl;
    /*copy struct so that
    it won't clash the original list*/
    while(mylist!=NULL)
    {
        nl=mylist->next;
        free(mylist);
        mylist=nl;
    }
}
//print the elements in the list
void printlist(struct list* mylist)
{
    while (mylist != NULL)
    {
        //print the elements in the list
        printf("%d ", mylist ->info);
        mylist = mylist->next;
    }
    printf("\n");
}
//remove the first element of list
struct list* remove_front(struct list *mylist)
{
    struct list *nl;
    nl = mylist;
    if(nl==NULL)
    {
        return mylist;
    }
    nl = nl->next;
    mylist=nl;
    return mylist;
    free(nl);
    //free the list
}

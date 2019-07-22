/*
    JTSK-320112
    a3-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

//define doubly linked list
struct l_list
{
    char info;
    struct l_list *next;
    struct l_list *prev;
};
struct list
{
    struct l_list *head;
    struct l_list *tail;
};
//add an element to the front of list
struct list* push_front(struct list* mylist, char c)
{
    struct l_list *nl;
    nl=(struct l_list*)malloc(sizeof(struct l_list));
    //allocate the new list to push
    if(nl==NULL)
    {
        printf("Error allocating memory\n");
        return mylist;
    }
    //check for initially empty list
    if(mylist->head == NULL)
    {
        nl->prev = NULL;
        nl->next = NULL;
        nl->info = c;
        mylist->head = nl;
        mylist->tail = nl;
    }
    else
    {
        nl->info = c;
        nl->prev = NULL;
        //point to each other
        nl->next = mylist->head;
        mylist->head->prev = nl;
        //add the element to the list
        mylist->head = nl;
    }
    return mylist;
}
struct list* remove_one(struct list* mylist,
                        struct l_list *ml)
{
    //check the start and end of list
    if(ml==mylist->head && ml==mylist->tail)
    {
        mylist->head = NULL;
        mylist->tail = NULL;
        free(ml);
        return mylist;
    }
    //to remove the start if found
    else if(ml==mylist->head)
    {
        mylist->head = ml->next;
        mylist->head->prev = NULL;
        free(ml);
        return mylist;
    }
    //remove the end if found
    else if(ml==mylist->tail){
        mylist->tail = ml->prev;
        mylist->tail->next = NULL;
        free(ml);
        return mylist;
    }

    //point to each other
    ml->prev->next = ml->next;
    ml->next->prev = ml->prev;
    free(ml);
    return mylist;
};
struct list* remove_all(struct list* mylist,
                        char c)
{
    if(mylist->head == NULL)
        return mylist;
    struct l_list* nl;
    struct l_list* cursor=mylist->head;
    //point to the list passed from main

    //check whether the char is in the list
    int j=0;
    /*pointer shifts and compares the passed
    char with chars in the list*/
    while(cursor != NULL){
        nl = cursor->next;
        if(cursor->info==c){
            j=1;
            mylist = remove_one(mylist,cursor);
        }
        cursor=nl;
    }
    if(!j)
        printf("The element is not in the list!\n");
    return mylist;
}
//print the elements in the list
void printlist(struct list* mylist)
{
    struct l_list *nl = mylist->head;
    while (nl != NULL)
    {
        //print the elements in the list
        printf("%c ", nl ->info);
        nl = nl->next;
    }
    printf("\n");
    return;
}
//print elements in the list backwards
void printback(struct list* mylist)
{
    struct l_list *nl = mylist->tail;
    while(nl != NULL)
    {
        printf("%c ",nl->info);
        nl = nl->prev;
    }
    printf("\n");
    return;
}
void freelist(struct list* mylist){
    // deallocate
    struct l_list* cursor = mylist->head;
    struct l_list* nl;
    while(cursor!=NULL){
        nl = cursor->next;
        free(cursor);
        cursor = nl;
    }
    free(mylist);
    return;
}
int main()
{
    struct list *mylist;
    mylist=(struct list*)malloc(sizeof(struct list));
    //initialize by pointing to NULL
    mylist->head = NULL;
    mylist->tail = NULL;
    int i;
    char c;
    while(1)
    {
        scanf("%d",&i);
        getchar();
        switch(i)
        {
        case 1:
            scanf("%c",&c);
            getchar();
            mylist = push_front(mylist,c);
            break;
        case 2:
            scanf("%c",&c);
            getchar();
            mylist = remove_all(mylist,c);
            break;
        case 3:
            printlist(mylist);
            break;
        case 4:
            printback(mylist);
            break;
        case 5:
            freelist(mylist);
            return 0;
            break;
        default:
            printf("Not available\n");
            break;
        }
    }
}

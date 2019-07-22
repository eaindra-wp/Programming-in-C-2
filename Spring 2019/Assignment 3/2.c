/*
    JTSK-320112
    a3-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int info;
    struct list *next;
};
int k = 0;
//Counter for the list length

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
    k++;
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
    k++;
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
    k=0;
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
    k--;
    return mylist;
    free(nl);
    //free the list
}
//insert at the given node
struct list* insert_node(struct list *mylist,
                         int n,int value)
{
    //insert new element at specific location
    if (n<0 || n>k)
    {
        printf("Invalid position!\n");
        return mylist;
    }
    else
    {
        struct list *cursor,*nl,*next;
        nl =(struct list *)malloc(sizeof(struct list));
        //create a new list for insertion
        cursor = mylist;
        //copy the existing list
        if (nl==NULL)
        {
            printf("Error allocating memory\n");
            return mylist;
        }
        if (n==0)
        {
            nl->info = value;
            nl->next = mylist;
        }
        /*if the position is 0,the element
        will just be pushed from front.*/
        else
        {
            while(n>1)
            {
                /*the cursor will continue pointing to
                new elements before the final position
                is reached.*/
                cursor = cursor->next;
                n--;
            }
            /*after the loop breaks,the new
            element will be added to cursor list.*/
            next = cursor->next;
            nl->info = value;
            nl->next = next;
            cursor->next = nl;
        }
        k++;
        return mylist;
    }
}
//reversing the list
struct list* reverse(struct list *mylist)
{
    //reverse the linked list
    if (mylist==NULL)
        return mylist;
    else
    {
        struct list *cursor,*next,*prev;
        //copy the existing linked list
        cursor = mylist;
        //set up a null list
        prev = NULL;
        while (cursor != NULL)
        {
            /*As long as there are elements in
            the list,the remaining elements will be
            copied to a new list.Then,that remaining
            list will be assigned by the proceeding
            reversed elements in the list.*/
            next = cursor->next;
            cursor->next = prev;
            prev = cursor;
            cursor = next;
        }
        mylist = prev;
        return mylist;
    }
}
int main()
{
    struct list * mylist = NULL;
    char c;
    int i,n;
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
            case 'i':
                scanf("%d",&n);
                scanf("%d",&i);
                mylist= insert_node(mylist,n,i);
                break;
            case 'R':
                mylist=reverse(mylist);
                break;
        }
        getchar();
    }
}

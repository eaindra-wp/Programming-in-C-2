/*
    JTSK-320112
    a3-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
struct list
{
    int info;
    struct list *next;
};
struct list* push_back(struct list* mylist,
                       int value);
struct list* push_front(struct list* mylist,
                        int value);
void freelist(struct list* mylist);

void printlist(struct list* mylist);
struct list* remove_front(struct list *mylist);

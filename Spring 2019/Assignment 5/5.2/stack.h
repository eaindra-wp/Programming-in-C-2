/*
    JTSK-320112
    a5-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
struct stack
{
    unsigned int count;
    int array[100]; // Container
};
//header of the functions used
int isEmpty(struct stack *st);
int isFull(struct stack *st);
void push(int x,struct stack *st);
void pop(int n,struct stack *st);


/*
    JTSK-320112
    a5-p1.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
struct stack
{
    unsigned int count;
    int array[12]; // Container
};
//header of the functions used
int isEmpty(struct stack *st);
int isFull(struct stack *st);
void push(int x,struct stack *st);
struct stack *pop(struct stack *st);
void empty(struct stack *st);


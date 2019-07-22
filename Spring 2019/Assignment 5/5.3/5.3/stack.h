/*
    JTSK-320112
    a5-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
//for each word
struct arr
{
    char word[30];
};
//for each sentence
struct stack
{
    unsigned int count;
    struct arr array[30];
};

//header of the functions used
int isEmpty(struct stack *st);
int isFull(struct stack *st);
void push(char* x,struct stack *st);
char* pop(struct stack *st);


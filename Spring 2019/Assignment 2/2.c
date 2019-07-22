/*
    JTSK-320112
    a2-p2.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j;
    char c1[100],c2[100], *c3;
    scanf("%[^\n]s", (char*)&c1);
    getchar();
    scanf("%[^\n]s", (char*)&c2);
    getchar();
    //statically allocate two input arrays
    i=strlen(c1);
    j=strlen(c2);
    //getting the length of two input strings
    c3 = (char*)malloc(i+j);
    //dynamically allocate third array
    c3[0]='\0';
    strcat(c3,c1);
    strcat(c3,c2);
    //concatenate two inputs
    printf("Result of concatenation: %s\n",c3);
    free(c3);
}

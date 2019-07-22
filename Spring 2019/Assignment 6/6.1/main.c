/*
    JTSK-320112
    a6-p1.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int separator(char c)
{
    //check if there is still separator
    switch(c){
        case ' ':
        case ',':
        case '?':
        case '!':
        case '.':
        case '\t':
        case '\r':
        case '\n':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
int main()
{
    char c[50], ch, cc;
    fgets(c,50,stdin);
    c[strlen(c)-1] = '\0';
    cc = '\n';
    int i = 0;
    FILE *fp;
    fp = fopen(c,"r");
    if(fp == NULL)
    {
        fprintf(stderr,"Cannot open the file!\n");
        exit(1);
    }
    //read the entire file
    while(ch != EOF)
    {
        ch = getc(fp);
        //check if there are more separators
        if(separator(ch) && !separator(cc))
            i++;
        cc = ch;
    }
    printf("The file contains %d words.\n",i);
    fclose(fp);
}

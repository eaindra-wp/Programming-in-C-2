/*
    JTSK-320112
    a6-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
    char *user;
    int value;
}info;

/*char* read(FILE fp)
{
    char *l= (char*)malloc(sizeof(char)*30);
    if(fgets(l,sizeof(char)*30,fp))
    {
        for(int i=0, i<)
    }
}*/
int main()
{
    char name[30];
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]='\0';
    FILE *fp;
    fp = fopen(name,"r");
    if(fp == NULL)
    {
        fprintf(stderr, "Cannot open file!\n");
        exit(1);
    }
    fseek(fp,0,SEEK_END);
    int len= ftell(fp);
    printf("%d\n",len);
    char user[30],pass[30];
    while(1)
    {
        fgets(user,30,stdin);
        if(strcmp(user,"exit")==0)
            return 0;
        else
        {
            fgets(pass,30,stdin);
            user[strlen(user)-1]='\0';
            pass[strlen(pass)-1]='\0';
            fseek(fp,user*sizeof(info),SEEK_SET);
            printf("%d")
        }
    }
    fclose(fp);
}

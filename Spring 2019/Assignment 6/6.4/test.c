/*
    JTSK-320112
    a6-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 100

//to store index of passwords
typedef struct info
{
    char* user;
    int value;
} info;

//a linked list to store the info
typedef struct List
{
    info* data;
    struct List* next;
} List;

//look for the password
int cmp(List* head,char* user)
{
    if(head==NULL)
        return -1;
    if(strcmp(head->data->user,user)==0)
        return head->data->value;
    return cmp(head->next,user);
}

List* put(char* user,int value,List* head)
{
    //insert elements into the list
    info* p=(info*)malloc(sizeof(info));
    p->user=user;
    p->value=value;
    List* nn=(List*)malloc(sizeof(List));
    nn->data=p;
    nn->next=head;
    return nn;
    free(nn);
}

char* readuser(FILE* fp)
{
    char* line=(char*)malloc(sizeof(char)*LINE_LEN);
    if (fgets(line,LINE_LEN*sizeof(char),fp))
    {
        for(int i=0; i<LINE_LEN; i++)
        {
            if(line[i]=='\n')
                line[i]='\0';
        }
        return line;
    }
    return NULL;
    free(line);
}

int main()
{
    FILE* fp;
    char name[100];
    List* head=NULL;

    //get the file name
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]='\0';
    fp=fopen(name, "r");
    if(fp == NULL)
    {
        printf("Cannot open the file\n");
        exit(1);
    }
    char *l1,*l2,*l3;
    int pos;
    //read usernames from the file
    while((l1=readuser(fp)))
    {
        head=put(l1,ftell(fp),head);
        free(readuser(fp));
        //free the space to skip the line
    }
    while(1)
    {
        //accept user input
        l1=readuser(stdin);
        if(strcmp(l1,"exit")==0)
        {
            printf("Exiting ...\n");
            free(l1);
            return 0;
            break;
        }
        l2=readuser(stdin);
        //accept the password input

        pos=cmp(head,l1);
        //look for the username in the linked list
        if(pos == -1)
            printf("Access to user %s is denied.\n",l1);
        else
        {
            //if the username exists
            fseek(fp,pos,SEEK_SET);
            l3 = readuser(fp);
            //compare the passwords
            if(strcmp(l2,l3)==0)
            {
                printf("Access to user %s is granted.\n",l1);
            }
            else
            {
                printf("Access to user %s is denied.\n",l1);
            }
        }
    }
    fclose(fp);
}

/*
    JTSK-320112
    a6-p5.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //read number of files
    int n;
    scanf("%d", &n);
    getchar();
    //read names of files
    char *name[n];
    for(int i=0; i<n; i++)
    {
        name[i] = (char*)malloc(sizeof(char)*255);
        fgets(name[i], 255, stdin);
        name[i][strlen(name[i])-1]='\0';
    }
    //open output file
    FILE *fw;
    fw = fopen("output.txt","wb");

    if(fw==NULL)
    {
        //check if the file can be opened
        fprintf(stderr,"Cannot open file!\n");
        exit(1);
    }
    printf("Concating the content of %d files ...",n);
    printf("\nThe result is:\n");
    //open input files
    for(int i=0; i<n; i++)
    {
        FILE *fp;
        fp = fopen(name[i],"rb");
        if(fp == NULL)
        {
            fprintf(stderr,"Cannot open file!\n");
            exit(1);
        }
        //to read the files
        char *buf;
        fseek(fp,0,SEEK_END);
        int size = ftell(fp);
        fseek(fp,0,SEEK_SET);
        buf=(char*)malloc(sizeof(char)*64);
        //read the file
        fread(buf,1,64,fp);
        for(int i=0; i<size; i++)
        {
            printf("%c",buf[i]);
        }
        printf("\n");
        //print the text in the file
        if((size%64) != 0)
        {
            fwrite(buf,size,1,fw);
        }
        else
        {
            fwrite(buf,64,1,fw);
        }
        //write to output file
        strcpy(buf,"\n");
        fwrite(buf,sizeof(char),strlen(buf),fw);
        //set a new line after copying
        free(buf);
        fclose(fp);
    }
    //deallocate input files array
    for(int i=0; i<n; i++)
    {
        free(name[i]);
        //free the name lists
    }
    fclose(fw);
    printf("The result was written into output.txt\n");
    return 0;
}

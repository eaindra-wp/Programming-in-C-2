/*
    JTSK-320112
    a2-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int*** allocate_3d(int r,int c,int d)
{
    /*3d array is a stack of 2d arrays.
    So,the size of the stack is allocated
    first.*/
    int*** a = (int***)malloc(sizeof(int**)*d);
    //for row size
    if (a==NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    for(int i=0; i<d; i++)
    {
        //for row size
        a[i] = (int**)malloc(sizeof(int*)*r);
        if (a[i]==NULL)
        {
            exit(1);
        }
        for(int j=0; j<r; j++)
        {
            //for column size
            a[i][j]=(int*)malloc(sizeof(int)*c);
            if(a[i][j]==NULL)
            {
                exit(1);
            }
        }
    }
    return a;
}
void input_matrix(int ***a,int r,int c,int d)
{
    int i,j,k;
    /*read inputs by iterating row,column
    and depth in order*/
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            for (k=0; k<d; k++)
            {
                scanf("%d",&a[i][j][k]);
            }
        }
    }
}
void print_3d(int ***a,int r,int c,int d)
{
    int i,j,k;
    /*the depth number for each section
    is the same.The elements in all
    columns from the same row will
    be printed in order.The function
    will move to a new row after printing
    elements in all columns.*/
    for (i=0; i<d; i++)
    {
        /*elements from the same
        depth will be printed in
        2d format.*/
        printf("Section %d:\n",i+1);
        for(j=0; j<r; j++)
        {
            /*elements from all columns
            will be printed in order*/
            for(k=0; k<c; k++)
            {
                printf("%d ",a[j][k][i]);
            }
            printf("\n");
        }
    }
}
void free_3d(int ***a,int r,int c,int d)
{
    int i,j;
    //deallocate the 3d array
    for(i=0; i<d; i++)
    {
        for(j=0; j<c; j++)
        {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
}
int main()
{
    int r,c,d;
    scanf("%d",&r);
    scanf("%d",&c);
    scanf("%d",&d);
    //input for row,column & depth
    int*** a = allocate_3d(r,c,d);
    //to dynamically allocate 3d array
    input_matrix(a,r,c,d);
    //input elements of the array
    print_3d(a,r,c,d);
    //deallocate the 3d array
    free_3d(a,r,c,d);

    return 0;
}

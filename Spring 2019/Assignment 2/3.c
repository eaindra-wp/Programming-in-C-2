/*
    JTSK-320112
    a2-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int** allocate_matrix(int n,int m)
{
    int** a = (int**)malloc(sizeof(int*)*n);
    //for row size
    if (a==NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    for(int i=0; i<n; i++)
    {
        //for column size
        a[i] = (int*)malloc(sizeof(int)*m);
        if (a[i]==NULL)
        {
            exit(1);
        }
    }
    return a;
}
void free_matrix(int **a,int n)
{
    //free dynamically allocated matrices
    for(int i=0; i<n; i++)
    {
        free(a[i]);
    }
    free(a);
}
void input_matrix(int **a,int n,int m)
{
    int i,j;
    //read inputs for matrices
    for (i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void print_matrix(int **a,int n,int m)
{
    //print the values in matrices
    int i,j;
	for(i=0; i<n; i++)
    {
		for(j=0; j<m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void multiply(int *a[],int *b[],int *c[],int n,int m,int p)
{
    int i,j,k;
    //multiply 2 matrices and save the result
    for (i=0; i<n; i++)
    {
        for(j=0; j<p; j++)
        {
            c[i][j]= 0;
            /*set initial values,so random numbers
            won't be saved and printed.*/
            for(k=0; k<m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                /*save results of the multiplication
                of corresponding rows from 1st matrix
                and columns from 2nd matrix*/
            }
        }
    }
}
int main()
{
    int n,m,p;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&p);

    //dynamically allocate 3 matrices
    int** a = allocate_matrix(n,m);
    int** b = allocate_matrix(m,p);
    int** c = allocate_matrix(n,p);

    //read values for first 2 matrices
    input_matrix(a,n,m);
    input_matrix(b,m,p);

    printf("Matrix A:\n");
    print_matrix(a,n,m);
    printf("Matrix B:\n");
    print_matrix(b,m,p);

    multiply(a,b,c,n,m,p);
    //put multiply result of 2 matrices to 3rd matrix
    printf("The multiplication result AxB:\n");
    print_matrix(c,n,p);

    //deallocate three matrices
    free_matrix(a,n);
    free_matrix(b,m);
    free_matrix(c,n);
    return 0;
}

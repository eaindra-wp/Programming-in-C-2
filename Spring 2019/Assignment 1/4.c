/*
    JTSK-320112
    a1-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#define INTERMEDIATE

int main()
{
    int n,i,j,k,l,total=0;
    scanf("%d", &n);
    //set the size of vectors
    int *x, *y, *r;
    x= (int*)malloc(sizeof(int)*n);
    y= (int*)malloc(sizeof(int)*n);
    r= (int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &x[i]);
    }
    for(j=0; j<n; j++)
    {
        scanf("%d", &y[j]);
    }
    //add values for two vectors
    #ifdef INTERMEDIATE
    printf("The intermediate product values are:\n");
    for(l=0; l<n; l++)
    {
        r[l] = x[l]*y[l];
        printf("%d\n",r[l]);
    }
    #endif
    /*if the intermediate definition is removed,
    the above loop won't work.*/
    for(k=0; k<n; k++)
    {
        total += x[k]*y[k];
    }
    //Calculate the scalar product of 2 vectors
    printf("The scalar product is: %d\n", total);
    free(x);
    free(y);
    free(r);
    //deallocating arrays
    return 0;
}

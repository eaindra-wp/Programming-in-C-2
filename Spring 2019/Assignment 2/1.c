/*
    JTSK-320112
    a2-p1.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,f;
    scanf("%d", &i);
    float arr[i];
    float *arr1,*arr2;
    for(int j=0; j<i; j++)
    {
        scanf("%f",&arr[j]);
    }
    arr1 = &arr[0];
    arr2 = &arr[0];
    while(arr1!=NULL)
    {
        //look for a negative element
        if(*arr1>0)
        {
            arr1++;
        }
        //if found, the loop stops
        else
        {
            break;
        }
    }
    f = arr1-arr2;
    //find the location of negative element
    printf("Before the first negative value: %d elements\n",f);
}

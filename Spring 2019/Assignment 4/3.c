/*
    JTSK-320112
    a4-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//compare for ascending order
int ascend(const void *va,const void *vb)
{
    const int *a = (const int*)va;
    const int *b = (const int*)vb;
    //smaller value will be printed first
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}
//compare for descending order
int descend(const void *va,const void *vb)
{
    const int *a = (const int*)va;
    const int *b = (const int*)vb;
    //larger value will be printed first
    if(*a < *b)
        return 1;
    else if(*a > *b)
        return -1;
    else
        return 0;
}
//print the array
void print_arr(int *arr,int n)
{
    for (int j=0; j<n; j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
}
int main()
{
    int i,n,*arr;
    char c;
    scanf("%d",&n);
    //dynamically allocate an array
    arr = (int*)malloc(sizeof(int)*n);
    if (arr == NULL)
    {
        exit(1);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    getchar();
    //to accept char input
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'a':
                //for ascending order
                qsort(arr,n,sizeof(arr[0]),ascend);
                print_arr(arr,n);
                break;
            case 'd':
                //for descending order
                qsort(arr,n,sizeof(arr[0]),descend);
                print_arr(arr,n);
                break;
            case 'e':
                //exit
                free(arr);
                return 0;
                break;
            default:
                break;
        }
        getchar();
        //to accept another char input
    }
}

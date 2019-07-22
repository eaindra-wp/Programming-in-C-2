/*
    JTSK-320112
    a4-p4.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    char name[30];
    int age;
};
//bubblesort algorithm
void bubblesort(struct person *arr,int i,
                int(*cmp)(const struct person*,
                          const struct person*))
{
    struct person nl;
    int k = 1;
    while(k)
    {
        k=0;
        for(int j=1; j<i; j++)
        {
            if(cmp(&arr[j-1],&arr[j])>0)
            {
                nl = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = nl;
                k = 1;
            }
        }
    }
}
//name comparison
int name_cmp(const struct person *a,
             const struct person *b)
{
    int cmp_name = strcmp(a->name,b->name);
    //if names are the same
    if (cmp_name == 0)
        return (a->age < b->age? -1:1);
    else
        return cmp_name;
}
//age comparison
int age_cmp(const struct person *a,
            const struct person *b)
{
    if(a->age == b->age)
        //if ages are the same
        return (strcmp(a->name,b->name));
    else
        return (a->age < b->age? -1:1);
}
//print array list
void print_arr(struct person *arr,int n)
{
    for(int j=0; j<n; j++)
    {
        printf("{%s, %d}; ",arr[j].name,arr[j].age);
    }
    printf("\n");
}
int main()
{
    int i,j;
    scanf("%d",&i);
    struct person *arr;
    arr=(struct person*)malloc(sizeof(struct person)*i);
    //create a list of array
    for (j=0; j<i; j++)
    {
        scanf("%s",arr[j].name);
        getchar();
        scanf("%d",&arr[j].age);
        getchar();
    }
    //get user input for person data
    bubblesort(arr,i,name_cmp);
    //sort by name
    print_arr(arr,i);
    //sort by age
    bubblesort(arr,i,age_cmp);
    print_arr(arr,i);
}

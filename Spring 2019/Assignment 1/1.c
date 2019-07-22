/*
    JTSK-320112
    a1-p1.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#define swap(x,y,t) {t i=x;x=y;y=i;}
//swap by using 2 variables & datatype
//t-datatype, x,y-variables

int main()
{
    int f,g;
    double h,j;
    scanf("%d",&f);
    scanf("%d",&g);
    scanf("%lf",&h);
    scanf("%lf",&j);
    //accepting input
    swap(f,g,int);
    swap(h,j,double);
    //swap variables with macro
    printf("After swapping:\n");
    printf("%d\n%d\n",f,g);
    printf("%.6lf\n%.6lf\n",h,j);
}

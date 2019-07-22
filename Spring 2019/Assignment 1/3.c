/*
    JTSK-320112
    a1-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
#define minn(a,b)((a)<(b)?(a):(b))
#define min(a,b,c)(minn(minn((a),(b)),(c)))
//find min value among 3 numbers
#define maxx(a,b)((a)>(b)?(a):(b))
#define max(a,b,c)(maxx(maxx((a),(b)),(c)))
//find max vale among 3 numbers
#define mid(a,b,c){m=(min(a,b,c)+max(a,b,c))/2};
//mid value of inputs

int main()
{
    float a,b,c;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    //accept inputs
    float m = mid(a,b,c);
    printf("The mid-range is: %.6f\n",m);
    //print with precision of 6
    return 0;
}

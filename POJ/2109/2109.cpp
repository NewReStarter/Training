#include<stdio.h>
#include<cmath>
int main()
{
    double n,p;
    while(scanf("%lf%lf",&n,&p)!=EOF)
    {
        printf("%.0f\n",pow(p,1/n));
    } 
    return 0;   
}  
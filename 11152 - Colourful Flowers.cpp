/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1)

int main()
{
    double a,b,c;
    double rose,r,tri,s;

    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        s=(a+b+c)/2;
        tri=sqrt(s*(s-a)*(s-b)*(s-c));
        r=tri/s;
        rose=pi*r*r;

        printf("%0.4lf %0.4lf %0.4lf\n",(pi*pow((a*b*c)/(tri*4),2))-tri,tri-rose,rose);
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define Pi  3.141592653589793

int main()
{
    double a,b,c,x1,y1,x2,y2,x3,y3,s,A,d;

    while(scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
        b=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
        c=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
        s=(a+b+c)/2;
        A=sqrt(s*(s-a)*(s-b)*(s-c));
        d=(a*b*c)/(2*A);

        printf("%0.2lf\n",d*Pi);
    }
    return 0;
}

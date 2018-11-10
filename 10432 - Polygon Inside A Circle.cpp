/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

int main()
{
    double n,r;

    while(scanf("%lf%lf",&r,&n)!=EOF)
    {
        printf("%0.3lf\n",n*0.5*r*r*sin((2.0*PI)/n));
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n,p,k;
    while(scanf("%lf%lf",&n,&p)==2)
    {
        k=pow(p,1/n);
        printf("%.0lf\n",k);
    }
    return 0;
}

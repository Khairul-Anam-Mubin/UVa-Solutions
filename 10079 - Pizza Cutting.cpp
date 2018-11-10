/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,i,sum;

    while(scanf("%ld",&n)==1 && n>=0)
    {
        for(i=0,sum=1;i<=n;i++)
            sum+=i;
        printf("%ld\n",sum);
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum,n,k;

    while(scanf("%d%d",&n,&k)==2)
    {
        sum=n;
        while(n>=k){
            sum=sum+n/k;
            n=(n/k)+(n%k);
        }
        printf("%d\n",sum);
    }
    return 0;
}

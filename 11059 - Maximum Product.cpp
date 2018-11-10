/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t=0,n,a[20],p,m,i,j;

    while(scanf("%lld",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        m=0;
        for(i=0;i<n;i++){
            for(j=i,p=1;j<n && p;j++){
                p*=a[j];
                if(p>m)
                    m=p;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",++t,m);
    }
    return 0;
}

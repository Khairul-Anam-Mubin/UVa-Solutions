/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[51],m,i,n,sum,avg,t=0;

    while(scanf("%d",&n)==1&&n!=0)
    {
        for(i=1,sum=0;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        avg=sum/n;
        for(i=1,m=0;i<=n;i++){
            if(a[i]>avg){
                m+=(a[i]-avg);
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",++t,m);
    }
    return 0;
}

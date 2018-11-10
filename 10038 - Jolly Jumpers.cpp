/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i,j,temp,n,a[3000],sum,sum1;

    while(scanf("%lld",&n)==1)
    {
        sum=0;
        sum1=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=1;i<n;i++){
            a[i]=fabs(a[i]-a[i+1]);
        }
        for(j=1;j<n-1;j++){
            for(i=1;i<=n-1-j;i++){
                if(a[i]>a[i+1]){
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
        }
        for(i=1;i<n;i++){
            sum+=i;
        }
        for(i=1;i<n;i++){
            sum1+=a[i];
        }
        if(a[1]==1 && a[n-1]==n-1 && sum==sum1){
            printf("Jolly\n");
        }
        else if(n==1){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
    return 0;
}

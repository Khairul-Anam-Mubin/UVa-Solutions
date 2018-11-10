/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    double a[1000],avg,n,sum,v,pos,neg;

    while(scanf("%lf",&n)==1&&n!=0)
    {
        for(i=1,sum=0;i<=n;i++){
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        avg=sum/n;
        for(i=1,neg=0,pos=0;i<=n;i++){
            v= (long) ((a[i]-avg)*100.0)/100.0;
            if(v>0){
                pos+=v;
            }
            else{
                neg+=v;
            }
        }
        neg=-neg;
        printf("$%0.2lf\n",(neg>pos)?neg:pos);
    }
    return 0;
}

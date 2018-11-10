/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i;
    double d,v,u,t1,t2,t3;

    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf",&d,&v,&u);
        if(v>=u){
            printf("Case %d: can't determine\n",i);
        }
        else{
            t1=d/u;
            t2=d/sqrt(u*u-v*v);
            t3=t2-t1;
            if(t3<=0){
                printf("Case %d: can't determine\n",i);
            }
            else{
                printf("Case %d: %0.3lf\n",i,t3);
            }
        }
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,a,b;

    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++){
            int sum=0;
            scanf("%d",&a);
            scanf("%d",&b);
            while(a<=b){
                if( a%2 !=0 ){
                    sum=sum+a;
                }
                a++;
             }
          printf("Case %d: %d\n",i,sum);
        }
    }
    return 0;
}

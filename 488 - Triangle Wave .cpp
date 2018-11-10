/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,t,k,n,r,c,p;

    scanf("%d",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%d%d",&n,&c);
        for(r=1;r<=c;r++){
            for(i=1;i<=n;i++){
                for(j=1;j<=i;j++){
                    printf("%d",i);
                }
                printf("\n");
                if(i==n){
                    for(j=n-1;j>=1;j--){
                        for(k=j;k>=1;k--){
                            printf("%d",j);
                        }
                        printf("\n");
                    }
                }
            }
            if(p!=t || r!=c)
            printf("\n");
        }
    }
    return 0;
}

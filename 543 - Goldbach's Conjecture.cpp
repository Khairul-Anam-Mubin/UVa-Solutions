/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define mx 2000001
void sieve();
bool a[mx];

int main()
{
    sieve();
    int n,i,x;
    while(scanf("%d",&n)==1 && n!=0)
    {
        x=n/2;
        for(i=2;i<=x;i++){
            if(a[i]==false && a[n-i]==false){
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }
    }
    return 0;
}
void sieve()
{
    int i,j,sq;
    sq=sqrt(mx);
    a[0]=true;
    a[1]=true;
    for(i=2;i<=sq;i++){
        if(a[i]==false){
            for(j=i*i;j<mx;j+=i){
                a[j]=true;
            }
        }
    }

}

#include <bits/stdc++.h>

using namespace std;

#define mx 100000
void sieve();
bool a[mx];

int main()
{
    sieve();
    int n,i,x,cnt;
    while(scanf("%d",&n)==1 && n!=0)
    {
        x=n/2;
        cnt=0;
        for(i=2;i<=x;i++){
            if(a[i]==false && a[n-i]==false){
                cnt++;
            }
        }
        printf("%d\n",cnt);
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

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define Max 2000001
long int a[Max];
void sieve();

int main()
{
    long int n,flag,x,i,m,c,cnt;
    vector <long int> v;
    sieve();

    while(scanf("%ld",&n)==1 && n)
    {
        v.clear();
        if(n==1 || n==-1)
            continue;
        x=abs(n);
        c=sqrt(x);
        flag=0;
        if(x<Max-1){
            if(a[x]==0){
                if(n<0){
                    printf("%ld = -1 x %ld\n",n,x);
                }
                else{
                    printf("%ld = %ld\n",x,x);
                }
                continue;
            }
        }
        i=2;
        while(x!=1){
            if(x%i==0){
                v.push_back(i);
                x/=i;
                i=1;
            }
            if(i>=c && v.size()==0)
                break;
            i++;
        }
        printf("%ld = ",n);
        if(n<0 && v.size()==0){
            printf("-1 x %ld\n",x);
        }
        else if(n>0 && v.size()==0){
            printf("%ld\n",n);
        }
        else{
            if(n<0){
                printf("-1 x ");
            }
            for(i=0;i<v.size();i++){
                if(i==v.size()-1){
                    printf("%ld\n",v[i]);
                }
                else{
                    printf("%ld x ",v[i]);
                }
            }
        }
    }
    return 0;
}
void sieve()
{
    long int i,j,n;
    n=sqrt(Max);
    a[0]=1;
    a[1]=1;
    for(i=2;i<=n;i++)
        if(a[i]==0)
            for(j=i*i;j<=Max-1;j++)
                a[j]=1;
}

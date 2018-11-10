/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int prime(int x);

int main()
{
    long int i,j,k,n,s,c;

    while(scanf("%ld",&n)==1 && n!=0)
    {
        for(i=n-1;i>=(n/2);i--){
            if(prime(i)){
                k=n-i;
                if(prime(k)){
                    break;
                }
            }
        }
        if(i>k){
            printf("%ld = %ld + %ld\n",n,k,i);
        }
        else if(i<k){
            printf("%ld = %ld + %ld\n",n,i,k);
        }
        else{
            printf("%ld = %ld + %ld\n",n,k,i);
        }
    }
    return 0;
}
int prime(int x)
{
    int i,n=sqrt(x);

    if(x==1)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    for(i=3;i<=n;i+=2){
        if(x%i==0){
           return 0;
        }
    }
    return 1;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,i,x,s,r,j;

    while(scanf("%ld",&n)==1)
    {
        for(i=2;i<n;i++){
            if(n%i==0)
                break;
        }
        if(i!=n){
            printf("%ld is not prime.\n",n);
        }
        else{
            x=n;
            for(s=0;x!=0;){
                r=x%10;
                s=s*10+r;
                x=x/10;
            }
            for(j=2;j<s;j++){
                if(s%j==0)
                break;
            }
            if(j!=s){
                printf("%ld is prime.\n",n);
            }
            else{
                printf("%ld is emirp.\n",n);
            }
        }
    }
    return 0;
}

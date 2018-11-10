/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t,n,r,s,x,count;

    scanf("%lld",&t);
    while(t--)
	{
        scanf("%lld",&n);
        count=0;
        x=n;
        while(1){
            s=0;
            while(x!=0){
                r=x%10;
                s=s*10+r;
                x=x/10;
            }
            if(n==s){
                printf("%lld %lld\n",count,s);
                break;
            }
            else{
                x=n+s;
                n=x;
            }
            count++;
        }
    }
    return 0;
}

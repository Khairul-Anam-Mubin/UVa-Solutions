/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,x;
    int i,c,ara[15];

    while(scanf("%lld",&n)==1&&n>=0)
    {
        c=0;
        for(i=0;n!=0;i++){
            x=n%3;
            n=n/3;
            ara[i]=x;
            c++;
        }
        if(c==0){
            printf("0");
        }
        for(c=c-1;c>=0;c--){
            printf("%d",ara[c]);
        }
        printf("\n");
    }
    return 0;
}

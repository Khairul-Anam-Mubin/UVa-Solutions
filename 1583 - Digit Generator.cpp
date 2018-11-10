/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define Max 100001
long int gen[Max];
long int digitsum(long int n);
void check();

int main()
{
    check();
    long int t,n;

    scanf("%ld",&t);

    while(t--){
        scanf("%ld",&n);
        printf("%ld\n",gen[n]);
    }

    return 0;
}
long int digitsum(long int n)
{
    long int sum=n;
    while(n){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
void check()
{
    long int i,j;
    for(i=1;i<Max;i++){
        if(i<100){
            for(j=i/2;j<i;j++){
                if(digitsum(j)==i){
                    gen[i]=j;
                    break;
                }
            }
        }
        else{
            for(j=i-100;j<i;j++){
                if(digitsum(j)==i){
                    gen[i]=j;
                    break;
                }
            }
        }
    }
}

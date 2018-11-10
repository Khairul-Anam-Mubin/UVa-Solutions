/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int a,n;
    while(scanf("%ld",&n)==1&&n!=0)
    {
        a=n;
        while(1){
            if(n>=101){
                n=n-10;
                printf("f91(%ld) = %ld\n",a,n);
                break;
            }
            if(n<=100){
                n=n+11;
                if(n>=101){
                    n=n-10;
                }
            }
        }
    }
    return 0;
}

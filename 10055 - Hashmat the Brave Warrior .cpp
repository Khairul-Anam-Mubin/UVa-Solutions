/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int a,b;

    while(scanf("%ld%ld",&a,&b)==2)
    {
        if(a>b){
            printf("%ld\n",a-b);
        }
        else{
            printf("%ld\n",b-a);
        }
    }
    return 0;
}

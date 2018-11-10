/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum,n;

    while(scanf("%d",&n)==1)
    {
        sum=n;
        while(n>=3){
            sum=sum+n/3;
            n=(n/3)+(n%3);
        }
        if(n==2){
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,s,d,x,y;

    scanf("%ld",&n);

    while(n--)
    {
        scanf("%ld%ld",&s,&d);
        x=(s+d)/2;
        y=(s-d)/2;
        if(x<0||y<0||(s+d)%2!=0){
            printf("impossible\n");
        }
        else if(x>y){
            printf("%ld %ld\n",x,y);
        }
        else{
            printf("%ld %ld\n",y,x);
        }
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int t,n,a,b,c,sum=0;

    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        sum=0;
		
        while(n--){
            scanf("%ld%ld%ld",&a,&b,&c);
            sum+=a*c;
        }
        printf("%ld\n",sum);
    }
    return 0;
}

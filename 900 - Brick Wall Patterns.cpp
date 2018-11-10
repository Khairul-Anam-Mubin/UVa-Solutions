/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define Max 51
long long a[Max];

void fibonacci();

int main()
{
    fibonacci();
    ///freopen("output.txt","w",stdout);
    long long n;

    while(scanf("%lld",&n)==1 && n!=0
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
void fibonacci()
{
    long long x=1,y=0,i;
	
    for(i=1;i<=Max;i++){
        a[i]=x+y;
        y=x;
        x=a[i];
    }
}

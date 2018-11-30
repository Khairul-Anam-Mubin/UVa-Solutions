/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <stdio.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define pb push_back
typedef long long ll;

using namespace std;

int main()
{
    ll tc,l,n,u,x,m,mx,i,j,div;

    scanf("%lld",&tc);
    while(tc--)
    {
        mx=0;

        scanf("%lld%lld",&l,&u);

        for(i=l;i<=u;i++){
            n=sqrt(i);
            for(j=1,div=0;j<=n;j++){
                if(i%j==0){
                    div++;
                }
            }
            m=2*div;
            if(n*n==i){
                m--;
            }
            if(mx<m){
                mx=m;
                x=i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,x,mx);
    }
    return 0;
}

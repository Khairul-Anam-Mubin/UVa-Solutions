/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long p,c,a,l,t=0;

    while(scanf("%lld%lld",&a,&l)==2&&a>0 && l>0)
    {
        c=0;
        p=a;
        while(a<=l){

            if(a==1){
                c++;
                break;
            }
            else if(a%2==0){
                c++;
                a= a/2;
            }
            else if(a%2!=0){
                c++;
                a=3*a+1;
            }
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++t,p,l,c);
    }
    return 0;
}

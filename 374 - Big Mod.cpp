/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

using namespace std;

long long bigmod(long long b,long long p,long long m);
int main()
{
    long long B,P,M;

    while(scanf("%lld%lld%lld",&B,&P,&M)==3)
    {
        cout<<bigmod(B,P,M)<<endl;
    }
    return 0;
}
long long bigmod(long long b,long long p,long long m)
{
    long long x;
    if(p==0)
        return 1;
    else if(p%2==0){
        x=bigmod(b,p/2,m);
        return (x*x)%m;
    }
    else
        return ((b%m)*bigmod(b,p-1,m))%m;
}

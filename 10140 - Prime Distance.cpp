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
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

#define pb      push_back
#define Sqr(n)  (n*n)
#define Sort(v) sort(v.begin(),v.end())
#define Mxe(v)  *max_element(v.begin(),v.end())
#define Mne(v)  *min_element(v.begin(),v.end())
#define Fin     freopen("input.txt","r",stdin)
#define Fout    freopen("output.txt","w",stdout)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long int li;
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}

#define MOD 1000000007
#define MAX 1000000007
#define MIN -1000000007

//Code starts from here......

#define mx 100000
bool isp[mx+10];
vector <ll> prime;

void sieve()
{
    isp[1] = true;
    for(ll i = 4 ; i <= mx ; i += 2)
        isp[i] = true;
    for(ll i = 3 ; i*i <= mx ; i += 2)
        if(isp[i] == false)
            for(ll j = i*i ; j <= mx ; j +=(i+i))
                isp[j] = true;
    prime.pb(2);
    for(ll i = 3 ; i <= mx ; i += 2)
        if(isp[i] == false)
            prime.pb(i);
}
vector<bool> segmented(ll a , ll b)
{
    ll psize = prime.size();

    ll siz = b + a - 1;
    vector <bool>isp2(siz+1,0);
    ll sq = (ll)sqrt(b) + 1;
    if(a == 1)
        a++;
    for(ll i = 0 ; i < psize && prime[i] <= sq ; i++){
        ll p = prime[i];
        ll j = p*p;
        if(j < a)
            j = ((a + p - 1)/p) * p;
        for( ; j <= b ; j += p )
            isp2[j-a] = true;
    }
    return isp2;
}
int main()
{
    sieve();
    //Fout;
    ll U , L;

    while(scanf("%lld%lld",&U,&L) == 2){
        ll c1 = 0 , c2 = 0,close1=0 , close2 = 0 , d1 = 0 , d2 = 0 , mini = MAX , maxi = MIN;
        ll dis1 = 0, dis2 = 0;
        vector <bool> isp2;
        if(U==1)
            U++;
        isp2 = segmented(U,L);
        for(ll i = U ; i <= L ; i++){
            if(isp2[i-U] == false){
                if(c1 == 0)
                    c1 = i;
                else if(c2 == 0)
                    c2 = i;
                if(c1 != 0 && c2 != 0){
                    if(mini > Abs(c1-c2)){
                        close1 = c1;
                        close2 = c2;
                        mini = Abs(c1-c2);
                    }
                    swap(c1,c2);
                    c2 = 0;
                }
                if(d1 == 0)
                    d1 = i;
                else if(d2 == 0)
                    d2 = i;
                if(d1 != 0 && d2 != 0){
                    if(maxi < Abs(d1-d2)){
                        dis1 = d1;
                        dis2 = d2;
                        maxi = Abs(d1-d2);
                    }
                    swap(d1,d2);
                    d2 = 0;
                }
            }
        }
        //cout << close1 << " " << close2 << "\n";
        //cout << dis1 << " " << dis2 << "\n";
        if(close1 && close2 && dis1 && dis2)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",close1,close2,dis1,dis2);
        else
            printf("There are no adjacent primes.\n");
    }

    return 0;
}

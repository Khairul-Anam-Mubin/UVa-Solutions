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
#define MAX -1000000007
#define MIN 1000000007

//Code starts from here......

#define mx 1000000
bool ar[mx+10];
vector <ll> prime;

void sieve()
{
    ar[1] = true;
    for(ll i = 4 ; i <= mx ; i += 2)
        ar[i] = true;

    for(ll i = 3 ; i*i <= mx ; i += 2)
        if(ar[i] == false)
            for(ll j = i * i ; j <= mx ; j += (i+i))
                ar[j] = true;

    prime.pb(2);
    for(ll i = 3 ; i <= mx ; i += 2)
        if(ar[i] == false)
            prime.pb(i);
}

int main()
{
    // File input and outputs :     Fin ; Fout ;

    sieve();
    ll n ;
    while(cin >> n)
    {
        if(n < 0)
            break;

        ll siz = prime.size();

        for(ll i = 0 ; i < siz ; i++){
            while(n % prime[i] == 0){
                printf("    %lld\n", prime[i]);
                n /= prime[i];
            }
        }
        if(n != 1)
            printf("    %lld\n", n);
        cout << "\n";
    }

    return 0;
}

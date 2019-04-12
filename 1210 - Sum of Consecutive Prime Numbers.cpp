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
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1000000007

//Code starts from here......

#define mx 10000
bool isp[mx+10];
int dp[mx+10];
vector <int> prime;

void sieve()
{
    isp[1] = true;
    for(int i = 4 ; i <= mx ; i += 2 )
        isp[i] = true;
    for(int i = 3 ; i*i <= mx ; i += 2){
        if(isp[i] == false){
            for(int j = i*i ; j <= mx ; j += (i+i)){
                isp[j] = true;
            }
        }
    }
    prime.pb(2);
    for(int i = 3 ; i <= mx ; i += 2){
        if(isp[i] == false)
            prime.pb(i);
    }
}

int main()
{
    // File input and outputs :     Fin ; Fout ;

    sieve();

    int xz = prime.size();
    for(int i = 0 ; i < xz ; i++){
        int now = 0;
        for(int j = i ; j < xz ; j++){
            now += prime[j];
            if(now > mx)
                break;
            dp[now]++;
        }
    }
    int n ;
    while(cin >> n)
    {
        if(n == 0)
            break;
        cout << dp[n] << "\n";
    }

    return 0;
}

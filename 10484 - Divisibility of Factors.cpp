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
#include <bitset>
#include <algorithm>

#define pb       push_back
#define Sqr(n)   (n*n)
#define Sort(v)  sort(v.begin(),v.end())
#define Mxe(v)   *max_element(v.begin(),v.end())
#define Mne(v)   *min_element(v.begin(),v.end())
#define Fill0(a) memset(a,0,sizeof(a))
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T exgcd(T a,T b,T &x,T &y) {if(a<0){T d=exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.pb(s);return v;}
template <typename T> T isperfectsq(T x){ T n = sqrt(x); return ((n * n == x)?1:0);}

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1e9 + 7

//int dx[] = {0,0,-1,1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,-1,1,-1,1};

//Code starts from here....
typedef long long ll;
#define mxN 50000
bitset <mxN+10> isp;
vector <ll> prime;
ll sz ;
void sieve(){
    isp.set(1,1);
    for(ll i = 4 ; i <= mxN ; i += 2)
        isp.set(i,1);
    for(ll i = 3 ; i * i<= mxN ; i += 2){
        if(!isp.test(i)){
            for(ll j = i * i ; j <= mxN ; j += i+i){
                isp.set(j,1);
            }
        }
    }
    prime.pb(2);
    for(ll i = 3 ; i <= mxN ; i += 2){
        if(!isp.test(i)){
            prime.pb(i);
        }
    }
    sz = prime.size();
}
int main(){
    sieve();
    ll n , d ;
    while(scanf("%lld%lld",&n,&d) == 2){
        if(n == 0 && d == 0 )
            break;
        d = Abs(d);
        if(n == 0 && d == 1){
            printf("1\n");
            continue;
        }
        else if(n == 0 ){
            printf("0\n");
            continue;
        }
        map <ll,ll> mp1;
        for(ll i = 1 ; i <= n ; i++){
            ll x = i;
            ll sq = sqrt(x) ;
            for(ll j = 0 ; prime[j] <= sq && j < sz ; j++){
                while(x % prime[j] == 0){
                    mp1[prime[j]]++;
                    x /= prime[j];
                }
            }
            if(x > 1){
                mp1[x]++;
            }
        }
        ll sq = sqrt(d);
        int flag = 1;
        ll ans = 1;
        for(ll i = 0 ; prime[i] <= sq && i < sz ; i++){
            ll cnt = 0;
            if(d % prime[i] == 0){
                while(d % prime[i] == 0){
                    d /= prime[i];
                    cnt++;
                }
                if(mp1[prime[i]] < cnt || prime[i] > 100){
                    flag = 0;
                    break;
                }
                else{
                    ans *= ((mp1[prime[i]] - cnt) + 1);
                    mp1[prime[i]] = 0;
                }
            }
        }
        if(d > 1){
            if(mp1[d] < 1 || d > 100){
                flag = 0;
            }
            else{
                mp1[d]--;
            }
        }
        for(ll i = 2 ; i <= 97 && flag ; i++){
            ans = ans * (mp1[i]+1);
        }
        if(flag == 0)
            ans = 0;
        printf("%lld\n",ans);
    }
    return 0;
}

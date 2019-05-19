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

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1e9 + 7

//int dx[] = {0,0,-1,1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,-1,1,-1,1};

//Code starts from here......

int main(){
    int n ;
    cin >> n ;
    int ar[n+10] ;
    for(int i = 1 ; i <= n ; i++)
        cin >> ar[i];
    set <int> st;
    set <int> :: iterator it;
    for(int i = 1 ; i <= n ; i++)
        st.insert(ar[i]);
    int sz = st.size();
    int j = 1;
    for(it = st.begin() ; it != st.end() ; it++,j++)
        ar[j] = (*it);
    n =  sz;
    int query ;
    cin >> query ;
    while(query--){
        int x ;
        cin >> x ;
        int l = 1 ;
        int r = n ;
        int indx = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(ar[mid] == x){
                indx = mid ;
                break;
            }
            else if(ar[mid] < x)
                l = mid+1;
            else
                r = mid-1;
        }
        if(indx){
            if(indx != 1)
                cout << ar[indx-1] << " ";
            else
                cout << "X " ;
            if(indx != n)
                cout << ar[indx+1] ;
            else
                cout << "X";
        }
        else{
            int a , b;
            if(r == 0)
                r = l;
            if(x < ar[r]){
                b = ar[r];
                if(l != 1)
                    a = ar[r-1];
                else
                    a = -1;
            }
            else{
                a = ar[r];
                if(r != n)
                    b = ar[r+1];
                else
                    b = -1;
            }
            if(a != -1)
                cout << a << " ";
            else
                cout << "X ";
            if(b != -1)
                cout << b ;
            else
                cout << "X";
        }
        cout << "\n";
    }
    return 0;
}

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
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool isalpha(char ch){ if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1000000007

//Code starts from here......
bool check(int y , int x)
{
    map <int , int > st ;

    while(y){
        st[y%10]++;
        y /= 10;
    }
    while(x){
        st[x%10]++;
        x /= 10;
    }
    map <int , int> :: iterator it;
    if( st.size() != 10)
        return false;
    for(it = st.begin() ;  it != st.end() ; it++){
        if(it->second != 1)
            return false;
    }
    return true;
}
int main()
{
    int n , t = 0;
    while(scanf("%d",&n) == 1)
    {
        if(n == 0)
            break;
        if(t == 0)
            t = 1;
        else
            printf("\n");
        int flag = 1, f = 0 ;
        for(int i = 1234 ; i <= 98765 / n ; i++){
            int y = i;
            int x = n * y;
            int z  =  x;
            if(x > 98765)
                break;
            if(x < 10000)
                z = x * 10;
            if(y < 10000)
                y = y * 10;
            if(check(z,y) ==  true){
                if(x < 10000)
                    printf("0%d / %d = %d\n",x,i,n);
                else if(i < 10000)
                    printf("%d / 0%d = %d\n",x,i,n);
                else
                    printf("%d / %d = %d\n",z,i,n);
               f = 1;
            }
            else
                flag = 0;
        }
        if(flag == 0 && f == 0)
            printf("There are no solutions for %d.\n",n);
    }

    return 0;
}

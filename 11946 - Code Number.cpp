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

int main()
{
    //Fout;
    int tc ;
    cin >> tc ;
    getchar();
    while(tc--)
    {
        char str[101] ;
        while(gets(str))
        {
            if(str[0] == '\0')
                break;
            int len = strlen(str) ;
            for(int i = 0 ; str[i] ; i++){
                if(str[i] >= '0' && str[i] <= '9'){
                    if(str[i] == '0')
                        str[i] = 'O';
                    else if(str[i] == '1')
                        str[i] = 'I';
                    else if(str[i] == '2')
                        str[i] = 'Z';
                    else if(str[i] == '3')
                        str[i] = 'E';
                    else if(str[i] == '4')
                        str[i] = 'A';
                    else if(str[i] == '5')
                        str[i] = 'S';
                    else if(str[i] == '6')
                        str[i] = 'G';
                    else if(str[i] == '7')
                        str[i] = 'T';
                    else if(str[i] == '8')
                        str[i] = 'B';
                    else if(str[i] == '9')
                        str[i] = 'P';
                }
            }
            cout << str ;
            cout << "\n";
        }
        if(tc)
            cout << "\n";
    }
    return 0;
}

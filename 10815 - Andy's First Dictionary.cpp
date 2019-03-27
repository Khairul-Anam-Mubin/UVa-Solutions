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
#define Mex(v)  *max_element(v.begin(),v.end())
#define Men(v)  *min_element(v.begin(),v.end())
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

//Code starts from here......

int main()
{
    // File input and outputs :      Fin ; Fout ;

    string str;

    set <string> st;
    set <string> :: iterator it;

    while(cin >> str)
    {
        int len = str.size();
        
        string tmp;
        
        for(int i = 0 ; i < len ; i++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;

            if(str[i] >= 'a' && str[i] <= 'z')
                tmp.pb(str[i]);
            else if(!tmp.empty()){
                st.insert(tmp);
                tmp.clear();
            }
        }
        if(!tmp.empty())
            st.insert(tmp);
    }
    for(it = st.begin() ; it != st.end() ; it++)
        cout << *it << "\n";

    return 0;
}

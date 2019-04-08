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
#define MAX -1000000007
#define MIN 1000000007

//Code starts from here......

int main()
{
    int nodes ;
    while(cin >> nodes)
    {
        if(nodes == 0)
            break;
        int edges ;
        cin >> edges ;

        vector <int> adj[100000];
        int start ;
        for(int i = 0 ; i < edges ; i++){
            int x , y;
            cin >> x >> y;
            if(i == 0)
                start = x;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        int color[10000];
        for(int i = 0 ; i < 10000 ; i++)
            color[i] = -1;

        int flag = 1;
        queue <int> q;

        //starting node
        color[start] = 0;
        q.push(start);

        //BFS starts Here
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i = 0 ; i < adj[u].size();i++){
                if(color[adj[u][i]] == -1){
                    if(color[u] == 0)
                        color[adj[u][i]] = 1;
                    else
                        color[adj[u][i]] = 0;
                    q.push(adj[u][i]);
                }
                else{
                    if(color[adj[u][i]] == color[u]){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 0)
                break;
        }
        if(flag == 1)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}

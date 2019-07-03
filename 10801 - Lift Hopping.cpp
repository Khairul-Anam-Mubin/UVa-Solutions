/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
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
template <typename T> typename std::vector<T>::iterator insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> T isperfectsq(T x){ T n = sqrt(x); return ((n * n == x)?1:0);}

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.pb(s);return v;}

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1e12 + 7

//int dx[] = {0,0,-1,1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,-1,1,-1,1};

//Code starts from here....

struct node{
    int x , cost ;
    bool operator < (const node& p) const {
        return cost > p.cost ;
    }
};

int tim[5] ;
vector <int> v[6] ;
vector <node> G[1010] ;
int dist[1010] ;
int flag = 105 ;
int dump[10][1010] ;
void clr(int lifts) {
    for(int i = 0 ; i <= lifts ; i++)
        v[i].clear() ;
    return ;
}
void check(vector <int> v1 , vector <int> v2 , int lift1 , int lift2 ) {
    //cout << lift1 << " = " << lift2 << "\n" ;
    for(int i = 0 ; i < v1.size() ; i++) {
        for(int j = 0 ; j < v2.size() ; j++) {
                //cout << j  <<"access\n";
            if(v1[i] == v2[j]) {
                if(v1[i] == 0) {
                    G[0].pb({0 , 0}) ;
                }
                else{
                    G[v1[i]].pb({flag , 60}) ;
                    dump[lift2][v2[j]] = flag ;
                    G[flag].pb({v1[i] , 60}) ;
                    flag++;
                }
            }
        }
    }
    return ;
}
void dijkstra(int nodes ,int from ,int to ) {
    for(int i = 0 ; i <= nodes + 1 ; i++)
        dist[i] = 1e9 ;
    priority_queue <node> pq ;
    pq.push({from , 0});
    dist[from] = 0;
    while(!pq.empty()) {
        int u = pq.top().x ;
        int wu = pq.top().cost ;
        pq.pop() ;
        if(u == to) {
            return ;
        }
        if(wu > dist[u])
            continue ;
        for(int i = 0 ; i < G[u].size() ; i++) {
            int v = G[u][i].x ;
            int wv = G[u][i].cost ;
            if(wu + wv < dist[v]) {
                dist[v] = wu + wv ;
                pq.push({v , dist[v]}) ;
            }
        }
    }
    return ;
}
int main() {
    int lifts , destination ;
    while(scanf("%d%d",&lifts,&destination) == 2 ) {
        clr(lifts) ;
        Fill0(dump) ;
        for(int i = 0 ; i < lifts ; i++)
            scanf("%d",&tim[i]) ;
        getchar() ;
        vector <string> temp ;
        for(int i = 0 ; i < lifts ; i++ ) {
            string str ;
            getline(cin , str) ;
            temp = linetostr(str) ;
            for(int j = 0 ; j < temp.size() ; j++)
                v[i].pb(strtoint(temp[j])) ;
            temp.clear() ;
        }
       // cout << "ok\n" <<"\n";
        for(int i = 0 ; i < lifts - 1 ; i++) {
            for(int j = i+1 ; j < lifts ; j++) {
                check(v[i] , v[j], i , j) ;
            }
        }
        //cout << "ok22\n" ;

        for(int i = 0 ; i < lifts ; i++) {
            for(int j = 0 ; j < v[i].size() - 1 ; j++) {
                int now = Abs(v[i][j] - v[i][j+1]) ;
                now *= tim[i] ;
                int x = v[i][j] ;
                int y = v[i][j+1] ;
                if(dump[i][x] != 0) {
                    x = dump[i][x] ;
                }
                if(dump[i][y] != 0) {
                    y = dump[i][y] ;
                }
                G[x].pb({y , now}) ;
                G[y].pb({x , now}) ;
            }
        }
        dijkstra(1001 , 0 , destination) ;
        if(dist[destination] == 1e9)
            cout << "IMPOSSIBLE\n";
        else
            cout << dist[destination] << "\n";
        for(int i = 0 ; i <= 1000 ; i++) {
            G[i].clear() ;
        }
    }
    return 0;
}

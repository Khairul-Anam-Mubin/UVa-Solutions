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
#define INF 1e9
#define IINF 1e18

//int dx[] = {0,0,-1,1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,-1,1,-1,1};

//Code starts from here....

struct node{
    int x , cost ;
    node(int _x , int _cost) {
        x = _x ;
        cost = _cost ;
    }
    bool operator < ( const node& p) const {
        return cost > p.cost ;
    }
};
int ww[10] ;
vector <int> v[10] ;
vector <node> G[1010] ;
int dist[1010] ;
int dump[1010] ;
int lifts , destination ;
void clr() {
    for(int i = 0 ; i < 10 ; i++ )
        v[i].clear() ;
    for(int i = 0 ; i < 1010 ; i++ )
        G[i].clear() ;
    Fill0(dump) ;
    return ;
}
void makegraph() {
    map <int, int> mp ;
    int flag = 110 ;
    for(int i = 0 ; i < lifts ; i++)
        for(int j = 0 ; j < v[i].size() ; j++)
            mp[v[i][j]]++ ;
    for(int i = 0 ; i < lifts ; i++) {
        for(int j = 0 ; j < v[i].size() ; j++) {
            if(mp[v[i][j]] > 1 && v[i][j] != 0 && v[i][j] != destination) {
                dump[flag] = v[i][j] ;
                v[i][j] = flag ;
                flag++;
            }
        }
    }
    for(int i = 0 ; i < lifts ; i++) {
        for(int j = 0 ; j < v[i].size() - 1 ; j++) {
            int a, b, w, x, y;
            a = v[i][j] ;
            b = v[i][j+1] ;
            x = a ;
            y = b ;
            if(a > 105)
                a = dump[a] ;
            if(b > 105)
                b = dump[b] ;
            w = Abs(a-b) * ww[i] ;
            G[x].pb(node(y, w)) ;
            G[y].pb(node(x, w)) ;
        }
    }
    for(int i = 0 ; i < lifts - 1 ; i++) {
        for(int j = i + 1 ; j < lifts ; j++) {
            for(int k = 0 ; k < v[i].size() ; k++) {
                for(int b = 0 ; b < v[j].size() ; b++) {
                    int x = v[i][k] ;
                    int y = v[j][b] ;
                    int m = x ;
                    int n = y ;
                    if(m > 105)
                        m = dump[m] ;
                    if(n > 105)
                        n = dump[n] ;
                    if( m == n ) {
                        int w = 0 ;
                        if(m != 0)
                            w = 60 ;
                        G[x].pb(node( y, w)) ;
                        G[y].pb(node(x, w)) ;
                    }
                }
            }
        }
    }
    return ;
}
void dijkstra(int from , int to) {
    for(int i = 0 ; i <= 1000 ; i++)
        dist[i] = INF ;
    priority_queue <node> pq ;
    dist[from] = 0 ;
    pq.push(node(from , 0)) ;
    while(!pq.empty()) {
        int u = pq.top().x ;
        int wu = pq.top().cost ;
        pq.pop() ;
        if(u == to)
            return;
        if(wu > dist[u])
            continue ;
        for(int i = 0 ; i < G[u].size() ; i++) {
            int v = G[u][i].x ;
            int wv = G[u][i].cost ;
            if(wu + wv < dist[v]){
                dist[v] = wu + wv ;
                pq.push(node(v , dist[v])) ;
            }
        }
    }
    return ;
}
int main() {
    while(scanf("%d%d",&lifts,&destination) == 2) {
        clr() ;
        for(int i = 0 ; i < lifts ; i++)
            scanf("%d",&ww[i]) ;
        getchar() ;
        for(int i = 0 ; i < lifts ; i++ ) {
            string str ;
            getline(cin , str) ;
            vector <string> temp = linetostr(str) ;
            for(int j = 0 ; j < temp.size() ; j++)
                v[i].pb(strtoint(temp[j])) ;
        }
        makegraph() ;
        dijkstra(0 , destination) ;
        if(dist[destination] == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",dist[destination]) ;
    }
    return 0 ;
}

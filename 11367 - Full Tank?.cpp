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

int dx[] = {0,0,-1,1,-1,-1,1,1,0};
int dy[] = {1,-1,0,0,-1,1,-1,1,0};

// this is the pair..

struct edge{
	int x ;
	int dis ;
	bool operator < ( const edge& p) const {
		return dis > p.dis ;
	}
};
struct node{
	int x ;
	int cost ;
	int gass ;
	bool operator < ( const node& p) const {
		return cost > p.cost ;
	}
};
int price[1010] ;
vector <edge> G[1010] ;
int cost[1010][110] ;
void clean(int nodes) {
	for(int i = 0 ; i <= nodes ; i++) {
		G[i].clear() ;
	}
}
int dijkstra(int from ,int to , int capacity) {
	for(int i = 0 ; i <= 1000 ; i++) {
        for(int j = 0 ; j <= 100 ; j++) {
            cost[i][j] = INF ;
        }
	}
	priority_queue<node> pq ;
	// not taking distance but taking the cost and current capacity of gass
	// we only have to minimize the cost
	cost[from][0] = 0 ;
	//starting from starting node and going with 0 fuel
	pq.push({from , 0 , 0}) ;
	while(!pq.empty()) {
		int u = pq.top().x ;
		int wu = pq.top().cost ;
		int gas = pq.top().gass ;
		pq.pop() ;
		//if we reach our destination then its the minimum cost
		if(u == to)
			return wu ;
		if(wu > cost[u][gas])
			continue ;
        // we are staying in the same node and we are only filling one per unit
		if(gas < capacity) {
			int newgas = wu + price[u] ;
			if(cost[u][gas + 1] > newgas) {
				cost[u][gas + 1] = newgas ;
				pq.push({ u , newgas , gas + 1}) ;
			}
		}
		for(int i = 0 ; i < G[u].size() ; i++) {
			int v = G[u][i].x ;
			int wv = G[u][i].dis ;
			//if we can go in the other node within the current fuel then we are going
			if(wv <= gas) {
				int cap = gas - wv ;
				// path relaxing...
				if(wu < cost[v][cap]) {
					cost[v][cap] = wu ;
					pq.push({v , wu , cap}) ;
				}
			}
		}
	}
	return -1 ;
}
int main() {
	int nodes , edges ;
	while(cin >> nodes >> edges) {
		clean(nodes) ;
		for(int i = 0 ; i < nodes ; i++) {
			cin >> price[i] ;
		}
		for(int i = 0 ; i < edges ; i++) {
			int u , v , d ;
			cin >> u >> v >> d ;
			G[u].pb({v , d}) ;
			G[v].pb({u , d}) ;
		}
		int query ;
		cin >> query ;
		while(query--) {
			int capacity , from , to ;
			cin >> capacity >> from >> to ;
			int ans = dijkstra(from ,to , capacity) ;
			if(ans == -1) {
				cout << "impossible\n";
			}
			else {
				cout << ans << "\n" ;
			}
		}
	}
	return 0 ;
}

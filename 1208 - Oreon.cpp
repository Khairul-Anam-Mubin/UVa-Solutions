/***
**     Allahu Akbar
**
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
 
#include <bits/stdc++.h>
using namespace std;


#define F            first
#define S            second  
#define PB           push_back
#define MP           make_pair
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree < 
        int, 
        null_type , 
        less < int > , 
        rb_tree_tag , 
        tree_order_statistics_node_update > 
        ordered_set ;
// *st.find_by_order(k) ; kth element
//  st.order_of_key(k) ; number of element less than k  
*/
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {if(a<0){T d=Exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=Exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInvPrime (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T ModInvNotPrime(T a , T m) {T x , y ;Exgcd(a , m , x , y) ;x %= m ;if(x < 0) x += m ;return x ;}
template <typename T> typename std::vector<T>::iterator Insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> inline string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;}
 
char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
long long Strtoint(string str){stringstream ss(str);long long x = 0;ss >> x ;return x ;}
string Intostr(long long x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
 
const double pi = 2 * acos(0.0);

#define MOD 998244353
#define INF9 2147483647
#define INF18 9223372036854775806
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define eps 1e-8

//int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
//int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

//int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
//int dy[] = {1 , -1 , 0 , 0} ; 

//scanf(" %[^\n]", str) ;

// mxN have to define before...
const int mxN = 30;
struct DSU {
    vector <int> parent;
    vector <int> siz;
    DSU(int mxN) {
        mxN <<= 1;
        parent.resize(mxN + 1);
        siz.resize(mxN + 1);
    }
    void Makeset(int n) {
        for (int i = 0 ; i <= n ; i++) {
            parent[i] = n + i;
            parent[n + i] = n + i;
            siz[n + i] = 1;
        }
    }
    int Find(int u) {
        if (parent[u] == u) return u ;
        return parent[u] = Find(parent[u]) ;
    }
    void Union(int u , int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (siz[u] < siz[v]) swap(u , v);
            parent[v] = u;
            siz[u] += siz[v];
        }
    }
    bool SameSet(int u , int v) {
        return (Find(u) == Find(v)) ;
    }
    void MoveUtoSetV(int u , int v) {
        if (SameSet(u , v)) return;
        int x = Find(u);
        int y = Find(v);
        siz[x]--;
        siz[y]++;
        parent[u] = y;
    }
    int Size(int u) {
        return siz[Find(u)];
    }
} dsu(mxN);

struct MST {
    vector <pair<int, pair<int , int>>> edges;
    vector <pair<int, pair<int , int>>> mstedges;
    int nodes , mstcost;
    void ProcessKruskal() {
        sort(edges.begin() , edges.end());
        int cnt = 0 ;
        for (auto it : edges) {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if (!dsu.SameSet(u , v)) {
                dsu.Union(u , v);
                mstedges.push_back(make_pair(w , make_pair(u , v)));
                cnt++ , mstcost += w;
            }
            if (cnt + 1 == nodes)
                break ;
        }
    }
    void Init(int n , const vector<pair<int , pair<int , int>>> &_edges) {
        edges = _edges;
        nodes = n;
        mstcost = 0;
        dsu.Makeset(nodes);
    }
    void Init(int n) {
        nodes = n;
        mstcost = 0;
        dsu.Makeset(nodes);
        edges.clear();
    }
    void AddEdge(int u, int v, int w) {
        edges.push_back(make_pair(w , make_pair(u , v)));
    }
    void ShowEdgeList() {
        for (auto it : edges) {
            cout << it.second.first << " -> " << it.second.first << " " ;
            cout << it.first << "\n";
        }
    }
    void ShowMSTEdgeList() {
        for (auto it : mstedges) { 
            cout << it.second.first << " -> " << it.second.second << " ";
            cout << it.first << "\n";
        }    
    }
};
int main() {
    FasterIO
    MST Mst;
    int tc , test = 0; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector < pair <int, pair<int, int>>> g;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n - 1; v++) {
                int w; cin >> w;
                char c; cin >> c;
                if (w) {
                    g.push_back(make_pair( w, make_pair( u, v)));
                }
            }
            int w; cin >> w;
            if (w) {
                g.push_back(make_pair( w, make_pair( u, n - 1)));
            }
        }
        Mst.Init(n , g);
        Mst.ProcessKruskal();
        cout << "Case " << ++test << ":\n";
        for (auto it : Mst.mstedges) {
            cout << char(it.S.F + 'A') << "-" << char(it.S.S + 'A') << " " << it.F << "\n";
        }
    }
    return 0;
}

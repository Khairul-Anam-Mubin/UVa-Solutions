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
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
 
typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

#define MOD 998244353
#define INF9 2147483647
#define INF18 9223372036854775806
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define eps 1e-8

//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

//int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
//int dy[] = {1 , -1 , 0 , 0} ; 

//scanf(" %[^\n]", str) ;

const int mxN  = 100010 ;
const int po = 20 ;
vector <pair<int , int> > g[mxN] ; 
int N , root ;
int level[mxN] , parent[mxN] ;
ll weight[mxN] ;
ll sum[mxN] ;
int sptab[mxN][20] ;

int LCA(int u , int v) {
    if(level[u] < level[v])
        swap(u , v) ;
    int log ;
    for(log = 1 ; (1 << log) <= level[u] ; log++) ;
    log-- ;
    for(int i = log ; i >= 0 ; i--) {
        if(level[u] - (1 << i) >= level[v]) {
            u = sptab[u][i] ;
        }
    }
    if(u == v) return u ;
    for(int i = log ; i >= 0 ; i--) {
        if(sptab[u][i] != -1 && sptab[u][i] != sptab[v][i]) {
            u = sptab[u][i] ;
            v = sptab[v][i] ;
        }
    }
    return parent[u] ;
} 
void Dfs(int u , int par = -1) {
    if(par == -1) {
        level[u] = weight[u] = sum[u] = 0 ;
        parent[u] = -1 ; 
    }
    for(auto it : g[u]) {
        int v = it.F ;
        ll w = it.S ;
        if(v != par) {
            level[v] = level[u] + 1 ;
            weight[v] = w ;
            parent[v] = u ;
            sum[v] = sum[u] + w ;
            Dfs(v , u) ;
        }
    }
}
void SparseTable() {
    Dfs(root) ;
    for(int i = 0 ; i < N ; i++) {
        sptab[i][0] = parent[i] ;
    }
    for(int j = 1 ; (1 << j) < N ; j++) {
        for(int i = 0 ; i < N ; i++) {
            if(sptab[i][j - 1] != -1) { 
                sptab[i][j] = sptab[sptab[i][j - 1]][j - 1] ;
            }
        }
    }
}
void Reset() {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; (1 << j) < N ; j++) {
            sptab[i][j] = -1 ;
        }
        g[i].clear() ;
    }
}
int main() {
    FasterIO
    while(cin >> N && N != 0) {
        root = 1 ;
        Reset() ;
        for(int i = 1 ; i <= N - 1 ; i++) {
            int v ; cin >> v ;
            ll w ; cin >> w ;
            g[i].PB(MP(v , w)) ;
            g[v].PB(MP(i , w)) ;
        }
        SparseTable() ;
        int q ; cin >> q ;
        vector <ll> ans ;
        while(q--) {
            int u , v ; 
            cin >> u >> v ;
            ll ok = sum[u] + sum[v] - 2 * sum[LCA(u , v)] ;
            ans.PB(ok) ;
        }
        for(int i = 0 ; i + 1 < ans.size() ; i++) {
            cout << ans[i] << " " ;
        }
        cout << ans.back() << "\n" ;
    }

    return 0 ;
}

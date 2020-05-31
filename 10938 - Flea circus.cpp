/***
**                      ALLAHU AKBAR
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
#define File         F();
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0); 
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)

#define MOD          998244353
#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8 

const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void F(){
    #ifndef ONLINE_JUDGE 
        Fin;
        Fout; 
    #endif
}
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 
template <typename T> void Print(const vector<T> &v) {for (int i = 0; i + 1 < v.size() ; i++) cout << v[i] << " ";cout << v.back() << "\n";}

struct LowestCommonAncestor {
    int N , root = 1, po;
    
    vector <vector <int> > g;
    vector <vector <int> > sptab; 
    vector <int> depth;
    vector <int> parent;
    
    void Init(int _n) {
        N = _n; _n++;
        po = log2((_n)) + 1;
        g.assign(_n, {});
        depth.resize(_n);
        parent.resize(_n);
        sptab.assign(_n, {});
    }
    void AddEdge(int u , int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void Dfs(int u , int par = -1) {
        if(par == -1) {
            depth[u] = 0;
            parent[u] = -1;
        }
        for(int v : g[u]) {
            if (v == par) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            Dfs(v , u);
        }
    } 
    void SparceTable() {
        for(int i = 1 ; i <= N ; i++) sptab[i][0] = parent[i];
        for(int j = 1 ; (1 << j) < N ; j++) {
            for(int i = 1 ; i <= N ; i++) {
                if(sptab[i][j - 1] != -1) {
                    sptab[i][j] = sptab[sptab[i][j - 1]][j - 1];
                }
            }
        }
    }
    void Build() {
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 0 ; j <= po ; j++) {
                sptab[i].push_back(-1);
            }
        }
        Dfs(root);
        SparceTable();
    }
    int Lca(int u , int v) {
        if(depth[u] < depth[v]) swap(u , v);
        int log;
        for(log = 1 ; (1 << log) <= depth[u] ; log++); log--;
        for(int i = log ; i >= 0 ; i--) {
            if(depth[u] - (1 << i) >= depth[v]) {
                u = sptab[u][i];
            }
        }
        if(u == v) return u;
        for(int i = log ; i >= 0 ; i--) {
            if(sptab[u][i] != -1 && sptab[u][i] != sptab[v][i]) {
                u = sptab[u][i];
                v = sptab[v][i];
            } 
        }
        return parent[u];
    }
    int KthAncestor(int u, int k) {
        int log;
        for(log = 1 ; (1 << log) <= depth[u] ; log++); log--;
        for(int i = log ; i >= 0 ; i--) {
            if(k - (1 << i) >= 0) {
                u = sptab[u][i];
                k -= (1 << i);
            }
        }
        return u;
    }
    int Getdist(int u , int v) {
        return (depth[u] + depth[v] - (2 * (depth[Lca(u , v)]))) ;
    }
    bool IsAnsector(int u , int v) {
        int cur = Lca(u , v);
        if(cur == u) return 1;
        return 0;
    }
} lca;

void Solve(int u , int v) {
    if (lca.depth[u] < lca.depth[v]) swap(u , v);
    int dis = lca.Getdist(u , v);
    if (dis % 2) {
        u = lca.KthAncestor(u , dis / 2);
        v = lca.parent[u];
        if (u > v) swap(u , v);
        cout << "The fleas jump forever between " << u << " and " << v << ".\n";
    } else {
        cout << "The fleas meet at " << lca.KthAncestor(u, dis / 2 ) << ".\n";
    }
}
int main() {
    FasterIO
    File
    int n; while (cin >> n && n) {
        lca.Init(n);
        for (int i = 1; i <= n - 1; i++) {
            int u , v; cin >> u >> v;
            lca.AddEdge(u , v);
        }
        lca.Build();
        int q; cin >> q;
        while (q--) {
            int u , v; cin >> u >> v;
            Solve(u , v);
        }
    }
    return 0;
}

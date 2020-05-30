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

/**************************Segment tree*****************************/

const int mxN = 100000;
struct node {
    int ch[11] ;
    node() {
        for(int i = 0 ; i < 11 ; i++)
            ch[i] = 0 ;
    }
} ;
node segtree[mxN * 4] ;
node temp , p ;
vector <long long> ok;
void SBuild(int cur , int left , int right) {
    if(left == right) {
        segtree[cur].ch[ok[left]] = 1 ;
        return  ;
    }
    int mid = (left + right) / 2 ;
    SBuild(cur * 2 , left , mid) ;
    SBuild(cur * 2 + 1 , mid + 1 , right) ;
    for(int i = 0 ; i < 11 ; i++) {
        segtree[cur].ch[i] = segtree[cur * 2].ch[i] + segtree[cur * 2 + 1].ch[i] ;
    }
    return ;
}
void SUpdate(int cur , int left , int right , int pos , long long val) {
    if(pos > right || pos < left)
        return ;
    if(left == pos && right == pos) {
        segtree[cur].ch[ok[pos]] = 0 ;
        segtree[cur].ch[val] = 1 ;
        ok[pos] = val;
        return ;
    }
    int mid = (left + right) / 2 ;
    SUpdate(cur * 2 , left , mid , pos , val) ;
    SUpdate(cur * 2 + 1 , mid + 1 , right , pos , val) ;
    for(int i = 0 ; i < 11 ; i++)
        segtree[cur].ch[i] = segtree[cur * 2 ].ch[i] + segtree[cur * 2 + 1].ch[i] ;
    return ;
}
node *SQuery(int cur , int left , int right , int l , int r) {
    if(l > right || r < left) 
        return &temp ;
    if(left >= l && right <= r)
        return &segtree[cur] ;
    int mid = (left + right) / 2 ;
    node p1 = *SQuery(cur * 2 , left , mid , l , r) ;
    node p2 = *SQuery(cur * 2 + 1 , mid + 1 , right , l , r) ;
    for(int i = 0 ; i < 11 ; i++)
        p.ch[i] = p1.ch[i] + p2.ch[i] ;
    return &p ; 
}

/**************************HeavyLightDecomposition***********************/
/*  1.  All nodes are number from 0 to n - 1  */ 
/*  2.  simply Init(total nodes) and call AddEdge(u , v) for all the edges */
/*  3.  Must be Take the node value from input directly or use the 
        TakeNodeVal(nodeval) to assigning the node value */
/*  4.  Call Build() to construct hld and segment tree */
/*  5.  simply use the path query by query(u , v) and update(pos , val) */

struct HeavyLightDecompose {
    vector <vector <int> > g ; // graph
    vector <long long> node_val;
    int N , root = 0;
    vector <int> depth , parent , sub;
    // HLD staffs
    int chain_no, indx;
    vector <int> chain_head , chain_ind;
    vector <int> node_serial , serial_node;
    vector <long long> segarr; // tree on linear format
    void Init(int n) {
        N = n;
        g.assign(N , {});
        node_val.clear();
        segarr.resize(N);
        depth.resize(N);
        parent.resize(N);
        sub.resize(N);
        chain_head.assign(N, -1);
        chain_ind.resize(N);
        node_serial.resize(N);
        serial_node.resize(N);
    }
    void AddEdge(int u , int v) {
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    void TakeNodeVal(const vector <long long> &_node_val) {
        node_val = _node_val;
    }
    void Build() {
        Dfs(root);
        chain_no = 0, indx = 0;
        HLD(0);
        Build();
        ok = segarr;
        SBuild(1 , 0 , N - 1);
        //T.Init(segarr);
        //T.Build(1 , 0 , N - 1);
        //SBuild(1 , 0 , N - 1);
    }
    void Dfs(int u, int par = -1) {
        sub[u] = 1;
        if (par == -1) {
            depth[u] = 0;
            parent[u] = -1;
        }
        for (int v : g[u]) {
            if (v == par) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            Dfs(v , u);
            sub[u] += sub[v];   
        }
    }
    void HLD(int u , int par = -1) {
        if (chain_head[chain_no] == -1) chain_head[chain_no] = u;
        chain_ind[u] = chain_no;
        node_serial[u] = indx;
        serial_node[indx] = u;
        segarr[indx] = node_val[u]; // tree flatting..
        indx++;
        int heavychild = -1 , heavysize = 0;
        for (int v : g[u]) {
            if (v == par) continue;
            if (sub[v] > heavysize) {
                heavysize = sub[v];
                heavychild = v;
            }
        }
        if (heavychild != -1) HLD(heavychild , u);
        for (int v : g[u]) {
            if (v != par && v != heavychild) {
                chain_no++;
                HLD(v , u);
            }
        }
    }
    void Update(int p , int val) {
        //T.Update(1 , 0 , N - 1, node_serial[p] , -node_val[p]);
        //T.Update(1 , 0 , N - 1, node_serial[p] , val);
        SUpdate(1 , 0 , N - 1 , node_serial[p] , val);
        node_val[p] = val;
    }
    int Query(int u , int v) {
        node ans;
        for ( ; chain_ind[u] != chain_ind[v] ; v = parent[chain_head[chain_ind[v]]]) {
            if (depth[chain_head[chain_ind[u]]] > depth[chain_head[chain_ind[v]]])
                swap( u , v );
            node tmp = *SQuery(1 , 0 , N - 1 , node_serial[chain_head[chain_ind[v]]] , node_serial[v]);
            for (int i = 0; i < 11; i++) {
                ans.ch[i] = ans.ch[i] + tmp.ch[i];
            }
        }
        if (depth[u] > depth[v])
            swap(u , v);
        //ans += T.Query(1 , 0 , N - 1 , node_serial[u] , node_serial[v]);
        node tmp = *SQuery(1 , 0 , N - 1 , node_serial[u] , node_serial[v]);
        for (int i = 0; i < 11; i++) {
            ans.ch[i] = ans.ch[i] + tmp.ch[i];
        }
        int mx = 0;
        for (int i = 0 ; i < 11; i++) {
            mx = max(mx , ans.ch[i]);
        }
        return mx;
    }
} hd;
int main() {
    FasterIO
    Test {
        int n , m; cin >> n >> m;
        memset(segtree, 0 , sizeof(segtree));
        hd.Init(n);
        vector <long long> pos(n);
        for (int i = 0; i < n; i++) cin >> pos[i];
        hd.TakeNodeVal(pos);
        for (int i = 0; i < n - 1; i++) {
            int u , v; cin >> u >> v;
            u-- , v--;
            hd.AddEdge(u , v);
        }
        hd.Build();
        for (int i = 0 ; i < m; i++) {
            int q; cin >> q;
            if (q == 0) {
                int node ; cin >> node; node--;
                long long val; cin >> val;
                hd.Update(node , val);
            } else if (q == 1) {
                int u , v; cin >> u >> v;
                u-- , v--;
                cout << hd.Query(u , v) << "\n";
            }
        }
    }
    return 0;
}

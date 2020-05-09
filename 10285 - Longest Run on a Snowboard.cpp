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

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 

int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
int dy[] = {1 , -1 , 0 , 0} ;

const int mxN = 100;
int N , r , c;
int mp[mxN + 5][mxN + 5];
int ar[mxN + 5][mxN + 5];
int dis[mxN * mxN + 5];
bool vis[mxN * mxN + 5];
vector <int> g[mxN * mxN + 5];
vector <int> orders;

bool Check(int x , int y, int xx , int yy) {
    if (xx < r && yy < c && xx >= 0 && yy >= 0 && ar[x][y] > ar[xx][yy])
        return 1;
    return 0;
}
void LongestPath(int u) {
    for (int v : g[u]) {
        if (dis[v] < dis[u] + 1) {
            dis[v] = dis[u] + 1;
            LongestPath(v);
        }
    }
}
void Dfs1(int u ) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v])
            Dfs1(v);
    }
    orders.PB(u);
}
void TopSort() {
    for (int i = 0; i < N; i++) {
        if (!vis[i]) Dfs1(i);
    }
    reverse(orders.begin() , orders.end());
}
int main() {
    FasterIO
    Test {
        string s; cin >> s;
        cin >> r >> c;
        for (int i = 0 , cnt = 0; i < r; i++) {
            for (int j = 0; j < c; j++ , cnt++) { 
                cin >> ar[i][j];
                mp[i][j] = cnt;
            }
        }
        N = r * c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < 4; k++) {
                    if (Check(i , j, i + dx[k] , j + dy[k])) {
                        g[mp[i][j]].PB(mp[i + dx[k]][j + dy[k]]);
                    }
                }
            }
        }
        memset(vis , 0 , sizeof(vis));
        TopSort();
        memset(dis , 0 , sizeof(dis));
        for (int i = 0; i < orders.size(); i++) {
            if (dis[orders[i]] == 0) {
                dis[orders[i]] = 1;
                LongestPath(orders[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans , dis[i]);
            g[i].clear();
        }
        orders.clear();
        cout << s << ": " << ans << "\n";
    }
    return 0;
}

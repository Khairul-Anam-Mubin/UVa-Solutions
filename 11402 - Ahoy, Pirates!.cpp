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
 
typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);
 
// Functions && Templates...

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
template <typename T> string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;}
 
char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
 
#define MOD 4294967296
#define INF9 2147483647
#define INF18 9223372036854775807
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define eps 1e-8

//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

//int dx[] = {0 , 0 , -1 , 1} ; // right , left , forward , backward
//int dy[] = {1 , -1 , 0 , 0} ; 

//scanf(" %[^\n]", str) ;

#define mxN 1024010
int ar[mxN + 10] ;
int segtree[4 * mxN] ;
int lazy[4 * mxN] ;

void propagate(int cur , int left , int right) {
	if(lazy[cur] == 1) {
		segtree[cur] = (right - left + 1) * 1 ; 
	} else if(lazy[cur] == 2) {
		segtree[cur] = 0 ; 
	} else if(lazy[cur] == 3) {
		segtree[cur] = (right - left + 1) - segtree[cur] ; 
	}
	//cout << lazy[cur * 2] << " " << lazy[cur * 2 + 1] << "\n" ;
	if(left != right) {
		if(lazy[cur] == 1 || lazy[cur] == 2) {
			lazy[cur * 2] = lazy[cur] ;
			lazy[cur * 2 + 1] = lazy[cur] ;
		} else {
			if(lazy[cur * 2] == 3) {
				lazy[cur * 2] = 0 ;
			} else if(lazy[cur * 2] == 0) {
				lazy[cur * 2] = 3 ;
			} else if(lazy[cur * 2] == 1) {
				lazy[cur * 2] = 2 ;
			} else if(lazy[cur * 2] == 2) {
				lazy[cur * 2] = 1 ;
			}
			if(lazy[cur * 2 + 1] == 3) {
				lazy[cur * 2 + 1] = 0 ;
			} else if(lazy[cur * 2 + 1] == 0) {
				lazy[cur * 2 + 1] = 3 ;
			} else if(lazy[cur * 2 + 1] == 1) {
				lazy[cur * 2 + 1] = 2 ;
			} else if(lazy[cur * 2 + 1] == 2) {
				lazy[cur * 2 + 1] = 1 ;
			}
		}
	}
	lazy[cur] = 0 ;
	return ;
}
int Query(int cur , int left , int right, int l , int r) {
	if(l > right || r < left)
		return 0 ;
	if(lazy[cur] != 0) {
		propagate(cur , left , right) ;
	}
	if(left >= l && right <= r) {
		return segtree[cur] ;
	}
	int mid = (left + right) / 2 ;
	int p1 = Query(cur * 2 , left , mid , l , r) ;
	int p2 = Query(cur * 2 + 1 , mid + 1, right , l , r) ;
	return (p1 + p2) ;
}
void Update(int cur , int left , int right , int l , int r , int op) {
	if(lazy[cur] != 0 ) {
		propagate(cur , left , right) ;
	}
	if(l > right || r < left) 
		return ;
	if(left >= l && right <= r) {
		if(op == 1) {
			segtree[cur] = (right - left + 1) * 1 ;
		} else if(op == 2) {
			segtree[cur] = 0 ;
		} else if(op == 3) {
			segtree[cur] = (right - left + 1) - segtree[cur] ;
		}
		//cout << lazy[cur * 2] << " " << lazy[cur * 2 + 1] << "\n" ;
		if(left != right) {
			if(op == 1 || op == 2) { 
				lazy[cur * 2] = op ;
				lazy[cur * 2 + 1] = op ;
			} else {
				if(lazy[cur * 2] == 3) {
					lazy[cur * 2] = 0 ;
				} else if(lazy[cur * 2] == 0) {
					lazy[cur * 2] = 3 ;
				} else if(lazy[cur * 2] == 1) {
					lazy[cur * 2] = 2 ;
				} else if(lazy[cur * 2] == 2) {
					lazy[cur * 2] = 1 ;
				}
				if(lazy[cur * 2 + 1] == 3) {
					lazy[cur * 2 + 1] = 0 ;
				} else if(lazy[cur * 2 + 1] == 0) {
					lazy[cur * 2 + 1] = 3 ;
				} else if(lazy[cur * 2 + 1] == 1) {
					lazy[cur * 2 + 1] = 2 ;
				} else if(lazy[cur * 2 + 1] == 2) {
					lazy[cur * 2 + 1] = 1 ;
				}
				//lazy[cur * 2] = ((lazy[cur * 2] == 3)? 0 : 3) ;
				//lazy[cur * 2 + 1] = ((lazy[cur * 2 + 1] == 3)? 0 : 3) ;	
			}
		}
		return ;
	} 
	int mid = (left + right) / 2 ;
	Update(cur * 2 , left , mid , l , r , op) ;
	Update(cur * 2 + 1 , mid + 1 , right, l , r , op) ;
	segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
	return ;
}
void Build(int cur , int left , int right) {
	if(left == right) {
		segtree[cur] = ar[left] ;
		return ;
	}
	int mid = (left + right) / 2 ;
	Build(cur * 2 , left , mid ) ;
	Build(cur * 2 + 1 , mid + 1 , right) ;
	segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
	return ;
}
int main() {
	FasterIO
	int tc , test = 0 ;
	cin >> tc ;
	while(tc--) {
		memset(segtree , 0 , sizeof(segtree)) ;
		memset(lazy , 0 , sizeof(lazy)) ;
		int m ; cin >> m ;
		int n = 0 ;
		while(m--) {
			int k ; cin >> k ;
			string s ; cin >> s ;
			int len = s.size() ;
			for(int i = 0 ; i < k ; i++) {
				for(int j = 0 ; j < len ; j++) {
					ar[n++] = s[j] - '0' ;
				}
			}
		}
		/*
		for(int i = 0 ; i < n ; i++) {
			cout << ar[i] ;
		}
		cout << "\n" ;
		*/

		Build(1 , 0 , n - 1) ;
		int q ; cin >> q ;
		cout << "Case " << ++test << ":\n" ;
		int ok = 0 ;
		while(q--) {
			char ch ; cin >> ch ;
			int l , r ; cin >> l >> r ;
			if(l > r) swap(l , r) ;
			if(ch == 'F') {
				Update(1 , 0 , n - 1 , l , r , 1) ;
			} else if(ch == 'E') {
				Update(1 , 0 , n - 1 , l , r , 2) ;
			} else if(ch == 'I') {
				Update(1 , 0 , n - 1 , l , r , 3) ;
			} else if(ch == 'S') {
				int ans = Query(1 , 0 , n - 1, l , r) ;
				cout << "Q" << ++ok << ": " << ans << "\n" ;
			}
		}
	}

	return 0 ;
}

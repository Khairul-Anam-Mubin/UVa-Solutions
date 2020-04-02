#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
/*
支持更高的快速幂操作
expower.mod_pow(a,b,mod);
*/ 
struct expower {
    ull mod_mul(ull a, ull b, ull M) {
        ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
        return ret + M * (ret < 0) - M * (ret >= (ll)M);
    }
    ull mod_pow(ull b, ull e, ull mod) {
        ull ans = 1;
        for ( ; e ; b = mod_mul( b, b, mod), e /= 2)
            if (e & 1) ans = mod_mul(ans, b, mod);
        return ans % mod;
    }
} expower;
struct BigPrime {    
    /*
    Miller-Rubin素数判别
    is_prime(n);    
    */
    bool is_prime(ull n) { 
        if (n < 2 || n % 6 % 4 != 1) 
            return n - 2 < 2;
        ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        ull s = __builtin_ctzll(n - 1), d = n >> s;
        for (auto a : A) {
            ull p = expower.mod_pow(a, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n && i--)
                p = expower.mod_mul(p, p, n);
            if (p != n - 1 && i != s) 
                return 0;
        }
        return 1;
    }
    /*
    素因数分解
    ret=factorization(n);
    */
    ull pollard(ull n) {
        auto f = [n](ull x) { 
            return ( expower.mod_mul(x, x, n) + 1) % n;
        };
        if (!( n & 1)) 
            return 2;
        for (ull i = 2 ; ; i++) {
            ull x = i, y = f(x), p;
            while ((p = __gcd( n + y - x , n)) == 1)
                x = f(x) , y = f(f(y));
            if (p != n) return p;
        }
    }
    vector <ull> factorization(ull n){
        if (n == 1) return {};
        if (is_prime(n)) return {n};
        ull x = pollard(n);
        auto l = factorization(x), r = factorization(n/x);
        l.insert(l.end(), begin(r), end(r));
        return l;
    }
};
int main() {
    BigPrime ob;
    int tc; cin >> tc;
    while (tc--) {
        ull x; cin >> x;
        vector <ull> pf = ob.factorization(x);
        map <ull , int> mp;
        for (auto it : pf) mp[it]++;
        vector <pair<ull ,int>> ok;
        for (auto it : mp) ok.push_back(make_pair(it.first , it.second));
        cout << x << " = ";
        for (int i = 0; i + 1 < ok.size(); i++ ) {
            if (ok[i].second != 1) {
                cout << ok[i].first <<"^" << ok[i].second << " * "; 
            } else {
                cout << ok[i].first << " * ";
            }
        }   
        if (ok.back().second != 1) {
            cout << ok.back().first <<"^" << ok.back().second << "\n"; 
        } else {
            cout << ok.back().first << "\n";
        }
    }
    return 0 ;
}

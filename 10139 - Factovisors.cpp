#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll val, ll div, ll cnt) {
    ll totCnt = 0, d = div;
    while(1) {
        ll t = val/div;
        if(t == 0)
            break;
        totCnt += t, div *= d;
    }

    return totCnt >= cnt;
}

int main() {
	ll n, m;

	while(scanf("%lld%lld", &n, &m) == 2) {
		ll x = m;
		bool found = 1;

		for(ll i = 2; i * i <= x; ++i) {
			ll cnt = 0;

			while(x%i == 0)
				x /= i, ++cnt;

			if(cnt > 0 && !check(n, i, cnt)) { 
				found = 0;
				break;
			}
		}

		if(x > 1 && !check(n, x, 1))
			found = 0;
		
		if(found)
			printf("%lld divides %lld!\n", m, n);
		else
			printf("%lld does not divide %lld!\n", m, n);

	}

	return 0;
}

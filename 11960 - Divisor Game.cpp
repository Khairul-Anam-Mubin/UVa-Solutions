#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int divisors[mxN + 1];
struct node{
    int val , id;
    node() {
        val = 0;
        id = 0;
    }
    node(int _v, int _i) {
        val = _v;
        id = _i;
    }
} seg[4 * mxN];
node Merge(node a , node b) {
    if (a.val < b.val) return b;
    if (a.val > b.val) return a;
    if (a.id <= b.id) return b;
    return a;
}
void Build(int cur , int left , int right) {
    if (left == right) {
        seg[cur] = node(divisors[left], left);
        return;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1 , left , mid);
    Build(cur << 1 | 1 , mid + 1, right);
    seg[cur] = Merge(seg[cur << 1], seg[cur << 1 | 1]);
}
node Query(int cur , int left , int right, int l, int r) {
    if (right < l || left > r) return {0 , 0};
    if (l <= left && right <= r) return seg[cur];
    int mid = (left + right) >> 1;
    return Merge(Query(cur << 1 , left , mid, l , r) , Query(cur << 1 | 1, mid + 1, right, l , r));
}
void DivSieve() {
    for (int i = 1; i <= mxN; i++) {
        for (int j = i; j <= mxN; j += i) {
            divisors[j]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    DivSieve();
    Build(1 , 1 , mxN);
    
    int tc; cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << Query(1 , 1 , mxN , 1 , n).id << "\n";
    }
    return 0;
}

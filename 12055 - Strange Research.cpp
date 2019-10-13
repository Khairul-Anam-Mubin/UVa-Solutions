#include <bits/stdc++.h>

using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
struct node {
    int cnt ;
    string mn , mx ;
    node() {
        cnt = 0 ;
        mn = "" ;
        mx = "" ;
    }
};
string scramb(string str) {
    string s = str ;
    sort(s.begin() + 1 , s.end() - 1) ;
    return s ;
}
int main() {
    fasrerIO() ;
    int n ;
    unordered_map<string , node> mp ;
    while(cin >> n) {
        for(int i = 0 ; i < n ; i++) {
            string str ;
            cin >> str ;
            string s = scramb(str) ;
            node &ob = mp[s] ;
            ob.cnt++ ;
            if(ob.cnt == 1) {
                ob.mn = str ;
                ob.mx = str ;
            }
            else {
                ob.mn = min(ob.mn , str) ;
                ob.mx = max(ob.mx , str) ;
            }
        }
        int query ;
        cin >> query ;
        while(query--) {
            string str ;
            cin >> str ;
            string s = scramb(str) ;
            node &ob = mp[s] ;
            if(ob.cnt == 0) 
                cout << "0\n" ;
            else 
                cout << ob.cnt << " " << ob.mn << " " << ob.mx << "\n" ;
        }
        mp.clear() ;
    }

    return 0 ;
}

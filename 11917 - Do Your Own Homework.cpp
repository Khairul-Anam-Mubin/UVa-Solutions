#include <bits/stdc++.h>

using namespace std ;

int main() {
    int tc ,test = 0 ;
    cin >> tc ;
    while(tc--) {
        int n ;
        cin >> n ;
        map <string , int> mp ;
        for(int i = 0 ; i < n ; i++) {
            string str ;
            int x ;
            cin >> str >> x ;
            mp[str] = x ;
        }
        int days ;
        cin >> days ;
        string sub ;
        cin >> sub ;
        cout << "Case " << ++test << ": " ;
        if(mp[sub] > 0 && mp[sub] <= days) {
            cout << "Yesss\n" ;
        }
        else if(mp[sub] > 0 && mp[sub] <= days + 5) {
            cout << "Late\n" ;
        }
        else {
            cout << "Do your own homework!\n" ;
        }
    }
    return 0 ;
}

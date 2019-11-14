#include <bits/stdc++.h>

using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
int ans ;
struct node {
    int occur ;
    int endmark ; 
    node *next[26] ;
    node() {
        for(int i = 0 ; i < 26 ; i++)
            next[i] = NULL ;
        occur = 0 ;
        endmark = 0 ;
    } 
} ;
node *root ;
void Insert(string const& s) {
    node *cur = root ;
    int len = s.size() ;
    for(int i = 0 ; i < len ; i++) {
        int id = s[i] - 'a' ;
        if(cur->next[id] == NULL) 
            cur->next[id] = new node() ;
        cur = cur->next[id] ;
        cur->occur++ ;
    }
    cur->endmark = 1 ;
}
void DFSonTrie(node *cur , int cnt) {
    
    for(int i = 0 ; i < 26 ; i++) {
        if(cur->next[i] != NULL ) {
            if(cur->next[i]->occur == 1) 
                ans += cnt + 1 ;
            else {
                if(cur->next[i]->endmark) 
                    ans += cnt + 1 ;
                DFSonTrie(cur->next[i] , cnt + 1) ;
            }
        }
    }
}
void TrieClear(node *cur) {
    for(int i = 0 ; i < 26 ; i++)
        if(cur->next[i])
            TrieClear(cur->next[i]) ;
    delete cur ;
}
int main() {
    fasrerIO() ;
    int tc ;
    cin >> tc ;
    while(tc--) {
        root = new node() ;
        int n ;
        cin >> n ;
        ans = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            string str ;
            cin >> str ;
            Insert(str) ;
        }
        DFSonTrie(root , 0) ;
        cout << ans << "\n" ;
        TrieClear(root) ;
    }   
    return 0 ;
}

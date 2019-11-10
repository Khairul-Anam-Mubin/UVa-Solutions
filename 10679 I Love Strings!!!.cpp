#include <bits/stdc++.h>

using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
int dp[1010] ;
string str ,text ;
struct node {
    bool endmark ;
    vector <int> pos ;
    node *next[52] ;
    node() {
        endmark = false ;
        for(int i = 0 ; i < 52 ; i++) 
            next[i] = NULL ;
    }
};
node *root ;
void Insert(int ind) {
    node *curr = root ;
    int len = str.length() ;
    for(int i = 0 ; i < len ; i++) {
        int id ;
        if(str[i] >= 'a' && str[i] <= 'z')
                id = str[i] - 'a' ;
            else
                id = str[i] - 'A' + 26 ; 
        if(curr->next[id] == NULL) 
            curr->next[id] = new node() ;
        curr = curr->next[id] ; 
    }
    curr->endmark = true ;
    curr->pos.push_back(ind) ;
}
void Search() {
    node *curr = root ;
    int len = text.length() ;
    for(int x = 0 ; x < 52 ; x++) {
        for(int i = 0 ; i < len ; i++) {
            int id ;
            if(text[i] >= 'a' && text[i] <= 'z')
                id = text[i] - 'a' ;
            else
                id = text[i] - 'A' + 26 ; 
            //int id = text[i] - 'a' ;
            if(id != x && curr == root)
                continue ;
            if(curr->next[id] != NULL && curr->next[id]->endmark) {
                vector <int> ok = curr->next[id]->pos ;
                for(int j = 0 ; j < ok.size() ; j++) {
                    dp[ok[j]] = 1 ;
                }
                curr = curr->next[id] ;
            }
            else if(curr->next[id] != NULL) {
                curr = curr->next[id] ;
            }
            else if(curr->next[id] == NULL) {
                curr = root ;
            }
        }
    }
}
void ClearMemory(node *cur) {
    for(int i = 0 ; i < 52 ; i++)
        if(cur->next[i])
            ClearMemory(cur->next[i]) ;
    delete(cur) ;
}
int main() {
    fasrerIO() ;
    int tc ;
    cin >> tc ;
    while(tc--) {
        root = new node() ;
        cin >> text ;
        int query ;
        cin >> query ;
        for(int i = 1 ; i <= query ; i++) {
            cin >> str ;
            Insert(i) ;
        }
        Search() ;
        for(int i = 1 ; i <= query ; i++) {
            if(dp[i])
                cout << "y\n" ;
            else
                cout  << "n\n" ;
            dp[i] = 0 ;
        }
        ClearMemory(root) ;
    }
    return 0 ;
}

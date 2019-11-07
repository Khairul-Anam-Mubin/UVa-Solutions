#include <bits/stdc++.h>
using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
int pfix[1000010] ;
int last ;
int BuildPrefixArray(string pattern) {
    int len = pattern.length() ;
    pfix[0] = 0 ;
    last = 0 ;
    for(int i = 1 , j = 0 ; i < len ; ) {
        if(pattern[i] == pattern[j]) 
            pfix[i++] = ++j ;
        else {
            if(j == 0)  
                pfix[i++] = 0 ;
            else
                j = pfix[j - 1] ;
        }
        last = j ;
    }
    int ok = len - last ;
    return  (len % ok == 0) ? ok : len ;
}
int main() {
    fasrerIO() ;    
    int n ;
    cin >> n ;
    while(n--) {
        string text ;
        cin >> text ;
        int ans = BuildPrefixArray(text) ;
        cout << ans << "\n" ;
        if(n)
            cout << "\n" ;
        //cout << x << "\n" ;
        //if(text.length() % x == 0)
        //    cout << x << "\n" ;
        //else
        //    cout << "1\n" ;
        //for(int i = 0 ; i < text.size() ; i++) {
            //cout << pfix[i] << " " ;
        //}
        //cout <<  "\n" ;
        //cout << last <<  "\n" ;    
    }
    return 0 ;
}

#include <bits/stdc++.h>
using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
int pfix[1000010] ;
void BuildPrefixArray(string pattern) {
    int len = pattern.length() ;
    pfix[0] = 0 ;
    for(int i = 1 , j = 0 ; i < len ; ) {
        if(pattern[i] == pattern[j]) 
            pfix[i++] = ++j ;
        else {
            if(j == 0)  
                pfix[i++] = 0 ;
            else
                j = pfix[j - 1] ;
        }
    }
}
int main() {
    fasrerIO() ;
    string str ;
    while(cin >> str) {
        if(str == ".")
            break ;
        BuildPrefixArray(str) ;
        int len = str.length() ;
        int last = pfix[len - 1] ;
        int ans = (len % (len - last) == 0) ? len / (len - last) : 1 ;
        cout << ans << "\n" ;
    }
    return 0 ;
}

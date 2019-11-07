#include <bits/stdc++.h>
using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}

int pfix[1000010] ;
void BuildPrefixArray(string pattern) {
    int len =  pattern.length() ;
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
string KMP(string text , string pattern) {
    int len1 = text.size() ;
    int len2 = pattern.size() ;
    int large = 0 ;
    int j = 0 ;
    for(int i = 0 ; i < len1 ; ) {
        if(text[i] == pattern[j]) {
            i++ ;
            j++ ;
        }
        else {
            if(j == 0) {
                i++ ;
            }
            else {
                large = max(large , j) ;
                j = pfix[j - 1] ;
            }
        }
        if(j == len2)
            large = j ; 
    }
    large = max(large , j) ;
    string ok ;
    for(int i = 0 ; i < large ; i++) {
        ok.push_back(pattern[i]) ;
    }
    reverse(ok.begin() , ok.end()) ;
    return ok ;
}
int main() {
    fasrerIO() ;    
    int n ;
    cin >> n ;
    while(n--) {
        string text ;
        cin >> text ;
        string pattern ;
        pattern = text ;
        reverse(text.begin() , text.end()) ;
        BuildPrefixArray(pattern) ;
        string ans = KMP(text , pattern) ;
        //for(int i = 0 ; i < pattern.length() ; i++) {
        //    cout << pfix[i] ;
        //}
        cout << ans << "\n" ;
    }
    return 0 ;
}

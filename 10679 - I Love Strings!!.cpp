#include <bits/stdc++.h>

using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
// Building Prefix array
vector <int> BuildPrefixArray(string pattern) {
    vector <int> pfix(pattern.length()) ;
    pfix[0] = 0 ;
    for(int i = 1 ,j = 0 ; i < pattern.length() ; ) {
        if(pattern[i] == pattern[j]) {
            pfix[i] = j + 1 ;
            i++ ;
            j++ ;
        }
        else {
            if(j == 0) {
                pfix[i] = 0 ;
                i++ ;
            }
            else {
                j = pfix[j - 1] ;
            }
        }
    }
    return pfix ;
}
bool KMP(string text , string pattern) {
    vector <int> pfix = BuildPrefixArray(pattern) ;
    for(int i = 0 , j = 0 ; i < text.length() && j < pattern.length() ; ) {
        if(text[i] == pattern[j]) {
            i++ ;
            j++ ;
        }
        else {
            if(j == 0) {
                i++ ;
            }
            else {
                j = pfix[j - 1] ;
            }
        }
        if(j == pattern.length())
            return 1 ;
    }
    return 0 ;
}
int main() {
    fasrerIO() ;
    int tc ;
    cin >> tc ;
    while(tc--) {
        string text ;
        cin >> text ;
        int query ;
        cin >> query ;
        while(query--) {
            string pattern ;
            cin >> pattern ;
            if(KMP(text , pattern))
                cout << "y\n" ;
            else
                cout << "n\n" ;
        }
    }
    return 0 ;
}

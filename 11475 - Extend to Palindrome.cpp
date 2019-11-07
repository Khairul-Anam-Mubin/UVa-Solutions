#include <bits/stdc++.h>
 
using namespace std ;
 
void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
// Building Prefix array
int pfix[100010] ;
void BuildPrefixArray(string pattern) {
    int len = pattern.length() ;
    pfix[0] = 0 ;
    for(int i = 1 ,j = 0 ; i < len ; ) {
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
}
// searching...
string KMP(string text ,string pattern) {
    int len1 = text.length() ;
    int len2 = pattern.length() ;
    for(int i = 0 , j = 0 ; i < len1 ; ) {
        if(text[i] == pattern[j]) {
            i++ ;
            j++ ;
        }
        else {
            if(j != 0) {
                j = pfix[j - 1] ;
            }
            else {
                i++ ;
            }
        }
        if(len1 == i) {
            string add = "" ;
            for(int k = j ; k < len2 ; k++) {
                add.push_back(pattern[k]) ;
            }
            string ans = text + add ;
            return ans ;
        }
    }
}
int main() {
    fasrerIO() ;
    string ss1 ;
    while(cin >> ss1) {
        string ss2 = ss1 ;
        reverse(ss2.begin() , ss2.end()) ;
        BuildPrefixArray(ss2) ; 
        //for(int i = 0 ; i < ss2.length() ; i++) {
        //    cout << pfix[i] << " " ;
        //}
        //cout <<  "\n" ;
        cout << KMP(ss1 , ss2) << "\n" ;
    }
    return 0 ;
} 

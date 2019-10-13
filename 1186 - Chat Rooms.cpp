#include <bits/stdc++.h>

using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
char uptolow(char ch){
    if(ch >= 'A' &&  ch <= 'Z') ch += 32;
    return ch;
}
vector<string> linetostr(string str){
    string s;
    vector <string> v ;
    istringstream is(str);
    while(is >> s)v.push_back(s);
    return v;
}
int isconsonent(char ch) {
    ch = uptolow(ch) ;
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
        return 0 ;
    return 1 ;
}
int check1(vector <string> vec) {
    for(int i = 0 ; i < vec.size() ; i++) {
        int cnt = 0 ;
        for(int j = 0 ; j < vec[i].size() ; j++) {
            if(isconsonent(vec[i][j])) 
                cnt++ ;
            else
                cnt = 0 ;
            if(cnt > 5)
                return 0 ;
        }
    }
    return 1 ;
}
int check2(vector <string> vec , vector <int> cnt) {
    int ok = 0 ;
    for(int i = 0 ; i < vec.size() ; i++) {
        int c = 0 ;
        for(int j = 0 ; j < vec[i].size() ; j++) {
            if(isconsonent(vec[i][j])) 
                c++ ;
            else 
                c = 0 ;
            if(c > 4) {
                ok = 1 ;
                break ;
            }
        }
    }
    int x = 0 ;
    for(int i = cnt.size() - 1 ; i >= max(0 , (int)cnt.size() - 10) ; i--) {
        if(cnt[i] > 0)
            x++ ;
    }
    if(ok && x > 2)
        return 0 ;
    return 1 ;
}
int check3(string str , vector <string> save) {
    int cnt = 0 ;
    for(int i = save.size() - 1 ; i >= max(0 ,(int)(save.size() - 10)) ; i--) {
        if(save[i] == str)
            cnt++ ;
        if(cnt > 1)
            return 0 ;
    }
    return 1 ;
}
int cnt4(vector <string> vec) {
    int x = 0 ;
    for(int i = 0 ; i < vec.size() ; i++) {
        int cnt = 0 ;
        for(int j = 0 ; j < vec[i].size() ; j++) {
            if(isconsonent(vec[i][j]))
                cnt++ ;
            else
                cnt = 0 ;
            if(cnt > 4)
                x = 1 ;
        }
    }
    return x ;
}
int main() {
    fasrerIO() ;
    int tc ;
    while(cin >> tc) {
        cin.ignore() ;
        vector <string> save ;
        vector <int> cnt ;
        while(tc--) {
            string str ;
            getline(cin , str) ;
            vector <string> vec = linetostr(str) ;
            int flag = 1 ;
            if(!check1(vec)) 
                flag = 0 ;
            else if(!check2(vec , cnt)) 
                flag = 0 ;
            else if(!check3(str , save)) 
                flag = 0 ;
            if(flag)
                cout << "y\n" ;
            else
                cout << "n\n" ;
            save.push_back(str) ;
            cnt.push_back(cnt4(vec)) ;
        }
    }
    return 0 ;
}

#include <bits/stdc++.h>

using namespace std ;

#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

int main() {
    //Fin , Fout ;
    string str ;
    while(cin >> str) {
        int len = str.size() ;
        deque <char> dq ;
        int flag = 0 ;
        int cnt = 0 ;
        for(int i = 0 ; i < len ; i++) {
            if(str[i] == '[') {
                flag = 1 ;
                if(cnt == 0)
                    continue ;
                string kk ;
                while(cnt--) {
                    kk.push_back(dq.front()) ;
                    dq.pop_front() ;
                }
                int klen = kk.size() ;
                for(int i = 0 ; i < klen ; i++) {
                    dq.push_front(kk[i]) ;
                }
                cnt = 0 ;
                continue ;
            }
            else if(str[i] == ']') {
                flag = 0 ;
                string kk ;
                while(cnt--) {
                    kk.push_back(dq.front()) ;
                    dq.pop_front() ;
                }
                int klen = kk.size() ;
                for(int i = 0 ; i < klen ; i++) {
                    dq.push_front(kk[i]) ;
                }
                cnt = 0 ;
                //cout << " append " << kk << "\n" ;
                continue ;
            }
            if(flag == 1) {
                cnt++ ;
                dq.push_front(str[i]) ;
            }
            else {
                dq.push_back(str[i]) ;
            }
        }
        if(cnt != 0 && flag ) {
            string kk ;
                while(cnt--) {
                    kk.push_back(dq.front()) ;
                    dq.pop_front() ;
                }
                int klen = kk.size() ;
                for(int i = 0 ; i < klen ; i++) {
                    dq.push_front(kk[i]) ;
                }
        }
        while(!dq.empty()) {
            cout << dq.front() ;
            dq.pop_front() ;
        }
        cout << "\n" ;
    }

    return 0 ;
}

#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;

template <typename T> T Sqr(T x) { 
    T n = x * x ; 
    return n ;
}
template <typename T> T Pow(T B,T P){
    if(P == 0) return 1;
    if(P & 1) return B*Pow(B,P-1);
    else return Sqr(Pow(B,P/2));
}

int main() {
    FasterIO
    int n ;
    while(cin >> n && n) {
        deque<int> dq ;
        for(int i = 1 ; i <= n ; i++) {
            dq.push_back(i) ;
        }
        vector <int> vec ;
        while(dq.size() > 1) {
            vec.push_back(dq.front()) ;
            dq.pop_front() ;
            if(vec.size() == n - 1)
                break ;
            dq.push_back(dq.front()) ;
            dq.pop_front() ;
        }
        cout << "Discarded cards:" ;
        for(int i = 0 ; i < vec.size() ; i++) {
            if(vec.size() != i + 1)
                cout << " " <<vec[i] << "," ;
            else 
                cout << " " << vec[i] ;
        }
        cout << "\n" ;
        cout << "Remaining card: " << dq.front() << "\n" ;
    }
    return 0 ;  
}

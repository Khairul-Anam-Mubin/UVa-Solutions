#include <bits/stdc++.h>
using namespace std ;

struct node {
    string name ;
    long long date , month , year ;
};
node ar[101] ;
bool cmp(node a , node b) {
    if(a.year != b.year) {
        return a.year < b.year ;   
    } else {
        if(a.month != b.month) {
            return a.month < b.month ;
        } else {
            if(a.date != b.date) {
                return a.date < b.date ;
            } else {
                return 1 ;
            }
        }
    }
}   
int main() {
    int n  ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++) {
        cin >> ar[i].name ;
        cin >> ar[i].date >> ar[i].month >> ar[i].year ;
    }
    sort(ar , ar + n , cmp) ;
    /*
    for(int i = 0 ; i < n ; i++) {
        cout << ar[i].name << "\n" ;
    }
    */
    cout << ar[n - 1].name << "\n" << ar[0].name << "\n" ;
    return 0 ;
}

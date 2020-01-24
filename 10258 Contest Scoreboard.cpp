#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;

struct node {
    int prob[10] ;
    int mark ;
    int tim[10] ;
    node() {
        for(int i = 0 ; i < 10 ; i++) {
            prob[i] = 0  ;
            tim[i] = 0 ;
        }
        mark = 0 ;
    }
} ;
struct ok {
    int cont = 0 , tot = 0 , pen = 0;
} ;
bool cmp(ok a , ok b) {
    if(a.tot != b.tot) {
        return a.tot > b.tot ;
    } else {
        if(a.pen != b.pen) {
            return a.pen < b.pen ;
        } else {
            return a.cont < b.cont ;
        }
    }

}
int main() {
    int tc ;
    //cin >> tc ;
    scanf("%d\n",&tc) ;
    //getchar() ;
    //getchar() ;
    char line[50] ;
    while(tc--) {
        //int n ;
        //cin >> n ; 
        node ar[101] ;
        while(gets(line) && line[0] != '\0') {
            int cont , prob , tim ;
            char var ;
            //cin >> cont >> prob >> tim >> var ;
            sscanf(line, "%d %d %d %c", &cont, &prob, &tim, &var);
            ar[cont].mark = 1 ;
            if(var == 'C') {
                if(ar[cont].tim[prob] == 0) {
                    ar[cont].tim[prob] = tim ;
                    ar[cont].tim[prob] += ar[cont].prob[prob] * 20 ;
                }
            } else if(var == 'I') {
                ar[cont].prob[prob]++ ;
            }
        }
        vector <ok> vec ;
        for(int i = 1 ; i <= 100 ; i++) {
            if(ar[i].mark) {
                ok tmp ;
                tmp.cont = i ;
                for(int j = 0 ; j < 10 ; j++) {
                    if(ar[i].tim[j]) {
                        tmp.pen += ar[i].tim[j] ;
                        tmp.tot++ ;
                    }
                }
                vec.push_back(tmp) ;
            }
        }
        sort(vec.begin() , vec.end() , cmp) ;
        for(auto it : vec) {
            //cout << it.cont <<  " " << it.tot << " " << it.pen << "\n" ;
            printf("%d %d %d\n", it.cont , it.tot , it.pen) ;
        }
        if(tc)
            puts("");
    }

    return 0 ;
}

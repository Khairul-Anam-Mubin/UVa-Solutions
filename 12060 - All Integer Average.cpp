#include <bits/stdc++.h>

using namespace std ;

template <typename T> T gcd(T a,T b){
    if(a < 0)return gcd(-a,b);
    if(b < 0)return gcd(a,-b);
    return (b == 0)?a:gcd(b,a%b);
}
int digit(int x) {
    int cnt = 0 ;
    while(x) {
        x /= 10 ;
        cnt++ ;
    }
    return cnt ;
}
void PrintNum(int num, bool isNeg, int preceedLength, int longest) {
    if (isNeg)
        cout << "  ";
    cout << string(preceedLength, ' ') << setw(longest) << num << '\n';
}
int main() {
    int n ,test = 0 ;
    while(scanf("%d",&n) == 1 && n) {
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++) {
            int x ;
            scanf("%d",&x) ;
            sum += x ;
        }
        bool isNeg = (sum < 0) ? 1 : 0 ; 
        sum = abs(sum) ;
        printf("Case %d:\n" , ++test) ;
        if(sum % n == 0) {
            int ans = sum / n ;
            if(isNeg)
                printf("- %d\n", ans) ;
            else
                printf("%d\n" , ans) ;
        }
        else {
            bool isNeg = (sum < 0);
            sum = abs(sum);
            int preceed = sum / n;
            int preceedLength = digit(preceed);
            sum = sum % n;
            int g = gcd(sum, n);
            int num = sum / g, denom = n / g;
            int longest = max(digit(num), digit(denom));
            PrintNum(num, isNeg, preceedLength, longest);
            if (isNeg)
                cout << "- ";
            if (preceed)
                cout << preceed;
            cout << string(longest, '-') << '\n';
            PrintNum(denom, isNeg, preceedLength, longest);
        }
    }
    return 0 ;
}

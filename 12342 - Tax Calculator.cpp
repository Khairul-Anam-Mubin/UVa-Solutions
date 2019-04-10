#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll tc , t = 0;
    cin >> tc ;
    while(tc--)
    {
        double k ; cin >> k;
        double tax = 0.0;
        double x1 = 180000.0 , x2 = 300000.0 , x3 = 400000.0,x4 = 300000.0 ;
        double x = k;
        if(k <= x1){
            tax = 0;
            cout << "Case " << ++t << ": " << "0\n";

        }
        else{
            x = x - x1;
            if(x > 0){
                if(x < x2)
                    tax += (x * 0.1);
                else
                    tax += (x2 * 0.1);
            }
            x = x - x2;
            if(x > 0){
                if(x < x3)
                    tax += (x * 0.15);
                else
                    tax += (x3 * 0.15);
            }
            x = x - x3;
            if(x > 0){
                if(x < x4 )
                    tax += (x * 0.20);
                else
                    tax += (x4 * 0.20);
            }
            x = x - x4;
            if(x > 0)
                tax += (x * 0.25);
            tax = ceil(tax);
            ll x = tax;
            if(x < 2000)
                cout << "Case " << ++t << ": 2000\n";
            else
                cout << "Case " << ++t << ": " << x << "\n";
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c;
    while(cin >> a >> b >> c)
    {
        double s=(a+b+c)/2.0;
        double area=(4.0/3.0)*sqrt(s*(s-a)*(s-b)*(s-c));
        if(area > 0.0)
            printf("%0.3lf\n",area);
        else
            printf("-1.000\n");
    }

    return 0;
}

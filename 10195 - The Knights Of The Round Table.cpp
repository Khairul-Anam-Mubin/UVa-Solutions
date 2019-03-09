#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c;

    while(cin >> a >> b >> c)
    {
        if(a<=0||b<=0||c<=0){
            printf("The radius of the round table is: 0.000\n");
            continue;
        }

        double s=(a+b+c)*0.5;
        double area= sqrt(s*(s-a)*(s-b)*(s-c));
        double r= area/s;

        printf("The radius of the round table is: %0.3f\n",r);
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,r;

    while(cin >> a >> b)
    {
        printf("[%d;",a/b);
        //cout << a/b << " ";
        r=a%b;
        while(r!=1){
            //cout << b/r << " ";
            printf("%d,",b/r);
            a=b;
            b=r;
            r=a%b;

        }
        //cout << b;
        printf("%d]\n",b);
    }
    return 0;
}

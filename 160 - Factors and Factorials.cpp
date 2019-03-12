#include <bits/stdc++.h>

using namespace std;

#define mx 150
bool prime[mx+30];

void sieve()
{
    int sq = sqrt(mx);

    prime[0] = true;
    prime[1] = true;

    for(int i = 2; i<=sq; i++){
        if(prime[i]==false){
            for(int j = i*i; j<=mx;j+=i){
                prime[j] = true;
            }
        }
    }
}

int main()
{
    sieve();

    int n;
    while(cin >> n)
    {
        if(n==0)
            break;

        vector <int> v(mx,0);
        int x = n;
        for(int i = 2; i<=x ; i++){
            if(prime[i]==false){
                int j = i;
                int tot = 0;
                int y = 0;

                while(true){
                    tot += x/j;
                    y = x/j;

                    if(y==0)
                        break;
                    j *= i;
                }
                v[i] = tot;
            }
        }

        printf("%3d! =",n);

        for(int i = 2,cnt = 1 ; i<=n ; i++){
            if(prime[i]==false){
                if(cnt==16){
                    printf("\n%6c",' ');
                    printf("%3d",v[i]);
                }
                else{
                    printf("%3d",v[i]);
                }
                cnt++;
            }
        }
        cout << "\n";
    }

    return 0;
}

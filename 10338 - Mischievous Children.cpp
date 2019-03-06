#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define mx 21
ull arr[mx+10];

void factorial()
{
    arr[1]=1;
    for(int i=2;i<=mx;i++){
        arr[i]=arr[i-1]*i;
    }
}

int main()
{
    factorial();

    int tc,t=0;
    scanf("%d",&tc);

    while(tc--)
    {
        char str[30];
        scanf("%s",str);

        vector <int> v(30,0);

        int len=strlen(str);
        ull fact=arr[len];

        for(int i=0;i<len; i++){
            v[str[i]-64]++;
        }
        for(int i=1;i<=26; i++){
            if(v[i]>1){
                fact/=arr[v[i]];
            }
        }
        //cout << fact << "\n";
        printf("Data set %d: %llu\n",++t,fact);
    }
    //cout << factorial(n);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define mx 46360
int isp[mx+10];
int prime[10000];
int k;
void sieve(){
    isp[1] = 1;
    for(int i = 4 ; i <= mx ; i += 2){
        isp[i] = 1;
    }
    for(int i = 3 ; i*i <= mx ; i += 2){
        if(!isp[i]){
            for(int j = i*i ; j <= mx ; j += i+i){
                isp[j] = 1;
            }
        }
    }
    k = 1;
    prime[0] = 2;
    for(int i = 3; i <= mx ; i+=2 ){
        if(!isp[i]){
            prime[k++] = i;
        }
    }
}
int primefact(int x){
    int sz = k;
    int sq = sqrt(x);
    int sum = 0;
    int n = x;
    for(int i = 0 ; i < sz  && sq >= prime[i] ; i++){
        int ok = 1;
        if(x % prime[i] == 0){
            while(x % prime[i] == 0){
                x /= prime[i];
                ok *= prime[i];
            }
            sum += ok;
        }
    }
    if(x > 1)
        sum += x;
    if(sum == n)
        sum++;
    if(n == 1)
        sum = 2;
    return sum;
}
int main(){
    //freopen("out.txt","w",stdout);
    sieve();
    int n , tc = 0;
    while(scanf("%d",&n) == 1 && n){
        printf("Case %d: ",++tc);
        if(n == 2147483647){
            printf("2147483648\n");
            continue;
        }
        int ans = primefact(n);
            printf("%d\n",ans);
    }
    return 0;
}


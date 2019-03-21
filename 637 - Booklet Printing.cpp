/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

#define pb      push_back
#define Sqr(n)  (n*n)
#define Mex(v)  *max_element(v.begin(),v.end())
#define Men(v)  *min_element(v.begin(),v.end())
#define Fin     freopen("input.txt","r",stdin)
#define Fout    freopen("output.txt","w",stdout)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}


//Code starts from here......

int main()
{
    int n ;

    while(scanf("%d",&n)==1 && n)
    {
        printf("Printing order for %d pages:\n",n);
        int tt = (n%4==0)?n/2:(n/2)+1;

        int x = n%4;
        int k = 1;
        if(n == 1){
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }
        if(x == 0){
            for(int i = 1 , r = n; i <= tt ; i++,r--){
                if(i%2){
                    printf("Sheet %d, front: %d, %d\n",k,r,i);
                }
                else{
                    printf("Sheet %d, back : %d, %d\n",k,i,r);
                    k++;
                }
            }
        }
        else if(x == 3){
            for(int i = 1 , r = n; i <= tt ; i++){
                if(i%2){
                    if(i == 1){
                        printf("Sheet %d, front: Blank, %d\n",k,i);
                        continue;
                    }
                    printf("Sheet %d, front: %d, %d\n",k,r,i);
                    r--;
                }
                else{
                    printf("Sheet %d, back : %d, %d\n",k,i,r);
                    k++;
                    r--;
                }
            }
        }
        else if(x == 2){
            for(int i = 1 , r = n; i <= tt ; i++){
                if(i%2){
                    if(i == 1){
                        printf("Sheet %d, front: Blank, %d\n",k,i);
                        continue;
                    }
                    printf("Sheet %d, front: %d, %d\n",k,r,i);
                    r--;
                }
                else{
                    if(i == 2){
                        printf("Sheet %d, back : %d, Blank\n",k,i);
                        k++;
                        continue;
                    }
                    printf("Sheet %d, back : %d, %d\n",k,i,r);
                    k++;
                    r--;
                }
            }
        }
        else{
            for(int i = 1 , r = n; i <= tt+1 ; i++){
                if(i%2){
                    if(i == 1 || i==3 ){
                        printf("Sheet %d, front: Blank, %d\n",k,i);
                        continue;
                    }
                    printf("Sheet %d, front: %d, %d\n",k,r,i);
                    r--;
                }
                else{
                    if(i == 2){
                        printf("Sheet %d, back : %d, Blank\n",k,i);
                        k++;
                        continue;
                    }
                    printf("Sheet %d, back : %d, %d\n",k,i,r);
                    k++;
                    r--;
                }
            }
        }
    }
    return 0;
}

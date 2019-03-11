#include <bits/stdc++.h>

using namespace std;


int main()
{
    int m,n,flag;

    while(cin >> n >> m)
    {
        if(n>=m){
            printf("%d divides %d!\n",m,n);
            continue;
        }
        flag=1;
        int sq=sqrt(m);
        int x=m;
        for(int i=2;i<=sq;i++){
            if(x%i==0){
                int cnt=0;
                while(x%i==0){
                    cnt++;
                    x/=i;
                }
                int y=n;
                int j=i;
                int k=0;
                int f=0;
                while(true)
                {
                    k+=n/j;
                    y=n/j;
                    if(k==0){
                        flag=0;
                        break;
                    }
                    if(k>=cnt){
                        f=1;
                        break;
                    }
                    if(y==0){
                        break;
                    }
                    j=j*i;
                }
                if(f==0){
                    flag=0;
                    break;
                }
                if(x==1){
                    break;
                }
            }
        }
        if(x>1){
            int s=n/x;
            if(s==0){
                flag=0;
            }
            else
                flag=1;
        }
        if(flag==1){
            printf("%d divides %d!\n",m,n);
        }
        else{
            printf("%d does not divide %d!\n",m,n);
        }
    }


    return 0;
}

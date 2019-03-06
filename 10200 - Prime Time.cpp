#include <bits/stdc++.h>

using namespace std;

#define mx 10000

bool uf[mx+100];

void Euler_Formula();

int main()
{
    Euler_Formula();

    int a,b;

    while(scanf("%d%d",&a,&b)==2)
    {
        double pr=0;

        for(int i=a;i<=b;i++){
            if(uf[i]==false)
                pr++;
        }
        double total=b-a+1;
        double percentage=(pr/total)*100;
        //printf("%0.2lf\n",percentage*100);
        printf("%0.2lf\n",percentage+1e-6);
    }
    return 0;
}
void  Euler_Formula()
{
    for(int i=0;i<=10000;i++){
        uf[i]=false;

        int flag=0;
        int x=(i*i)+i+41;
        if(x%2==0){
            flag=1;
        }
        else{
            int sq=(int)sqrt(x);
            for(int j=3;j<=sq;j+=2){
                if(x%j==0){
                    flag=1;
                    break;
                }
            }
        }
        if(flag){
            uf[i]=true;
        }
    }
    //for(int i=0;i<=10000;i++){
    //    cout << uf[i] << endl;
    //}    
}

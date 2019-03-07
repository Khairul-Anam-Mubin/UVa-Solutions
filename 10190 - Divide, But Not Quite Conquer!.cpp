#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        if(n<m || n==0 || m==0 || m<2){
            printf("Boring!\n");
            continue;
        }
        int flag=1,k=0,a[100];
        a[0]=n;

        for(int i=1;true;i++){
            if(a[i-1]%m!=0){
                flag=0;
                break;
            }
            else{
                a[i]=a[i-1]/m;
                k=i;
                if(a[i]==1){
                    break;
                }
            }
        }
        //for(int i=0;i<=k;i++){
        //    cout << a[i] << endl;
        //}
        if(flag){
            for(int i=0;i<=k;i++){
                if(i==k){
                    printf("%d\n",a[i]);
                }
                else{
                    printf("%d ",a[i]);
                }
            }
        }
        else{
            printf("Boring!\n");
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int ok,n,x;
void subsetsum(int p,int sum,int a[]);

int main()
{
    int i,tc,a[1005];

    scanf("%d",&tc);
    while(tc--)
    {
        ok=0;
        scanf("%d%d",&x,&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        subsetsum(0,0,a);

        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
void subsetsum(int p,int sum,int a[])
{
    if(x==sum){
        ok=1;
        return;
    }
    if(ok==1)
        return;
    if(p==n)
        return;

    subsetsum(p+1,sum,a);
    subsetsum(p+1,sum+a[p],a);
}

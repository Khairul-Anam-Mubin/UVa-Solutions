/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10000],i,j,n,c,temp;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0,c=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    c++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",c);
    }
    return 0;
}

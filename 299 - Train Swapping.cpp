/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include<bits/stdc++.h>

int main()
{
    int i,n,c,l,k,t,temp,a[51];

    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);

        for(k=0;k<n;k++)
            scanf("%d",&a[k]);
		
        for(k=0,c=0;k<n-1;k++){
            for(l=0;l<n-1-k;l++){
                if(a[l]>a[l+1]){
                    temp=a[l];
                    a[l]=a[l+1];
                    a[l+1]=temp;
                    c++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",c);
    }
    return 0;
}

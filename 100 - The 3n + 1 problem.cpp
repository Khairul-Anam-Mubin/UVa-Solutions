/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,n,m,p,temp;

    while(scanf("%d%d",&i,&j)==2)
	{
        m=0;
        printf("%d %d ",i,j);
        if(i>j){
            temp = j;
            j = i;
            i = temp;
        }
        for(p=i;p<=j;p++){
            n=1;
            for(k=p;k!=1;k=k){
                if(k%2==0){
					k = k / 2;
				}
                else{
                    k = 3 * k + 1;
				}
                n++;
           }
           if(n>=m){
            m=n;
           }
        }
        printf("%d\n",m);
    }
    return 0;
}

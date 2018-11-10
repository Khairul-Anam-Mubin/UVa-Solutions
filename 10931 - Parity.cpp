/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long int j,I,i,c,a[100];

    while(scanf("%lu",&I)==1&&I!=0)
    {
        for(i=1,c=0;I!=0;i++){
            a[i]=I%2;
            I=I/2;
           if(a[i]==1){
                c++;
            }
        }
        printf("The parity of ");
        for(j=i-1;j>=1;j--){
            printf("%lu",a[j]);
        }
        printf(" is %lu (mod 2).\n",c);
    }
    return 0;
}

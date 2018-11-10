/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int c=0,n,i,sum;

    while(scanf("%ld",&n)==1)
    {
        if(c==0){
             printf("PERFECTION OUTPUT\n");
             c++;
        }
        if(n==0){
            printf("END OF OUTPUT\n");
            break;
        }
        for(i=1,sum=0;i<=n/2;i++){
            if(n%i==0)
                sum+=i;
        }
         if(n>sum){
            if(n<10)
                printf("    %ld  DEFICIENT\n",n);
            else if(n<100)
                printf("   %ld  DEFICIENT\n",n);
            else if(n<1000)
                printf("  %ld  DEFICIENT\n",n);
            else if(n<10000)
                printf(" %ld  DEFICIENT\n",n);
            else
                printf("%ld  DEFICIENT\n",n);
        }
        else if(n<sum){
            if(n<10)
                printf("    %ld  ABUNDANT\n",n);
            else if(n<100)
                printf("   %ld  ABUNDANT\n",n);
            else if(n<1000)
                printf("  %ld  ABUNDANT\n",n);
            else if(n<10000)
                printf(" %ld  ABUNDANT\n",n);
            else
                printf("%ld  ABUNDANT\n",n);
        }
        else{
            if(n<10)
                printf("    %ld  PERFECT\n",n);
            else if(n<100)
                printf("   %ld  PERFECT\n",n);
            else if(n<1000)
                printf("  %ld  PERFECT\n",n);
            else if(n<10000)
                printf(" %ld  PERFECT\n",n);
            else
                printf("%ld  PERFECT\n",n);
        }
    }
    return 0;
}

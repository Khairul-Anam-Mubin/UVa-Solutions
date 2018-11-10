/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int prime(long int x);

int main()
{
    long int n,s,j,k,flag,c;

    while(scanf("%ld",&n)==1 && n!=0)
    {
        s=n/2;
        c=0;
        if(n%2){
            for(j = n-1,flag=0;j >= s; j--){
                if(prime(j)){
                    k=n-j;
                    if(j%2==1 || k%2==1){
                        if(prime(k)){
                            flag=1;
                            break;
                        }
                    }
                }
                c++;
                if(c>10000)
                    break;
            }
        }
        else{
            for(j = n-1,flag=0;j >= s; j--){
                if(prime(j)){
                    k=n-j;
                    if(prime(k)){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag){
            if(j<k)
                printf("%ld:\n%ld+%ld\n",n,j,k);
            else
                printf("%ld:\n%ld+%ld\n",n,k,j);
        }
        else
            printf("%ld:\nNO WAY!\n",n);
    }
    return 0;
}
int prime(long int x)  //x = checking x is prime or not
{                 //if prime return 1 else return 0
    int i,z;

    if(x==1)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    z=sqrt(x);
    for(i=3;i<=z;i+=2){
        if(x%i==0)
           return 0;
    }
    return 1;
}

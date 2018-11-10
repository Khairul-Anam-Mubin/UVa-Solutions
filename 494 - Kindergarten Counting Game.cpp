/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[10000];
    int i,c,s;

    while(gets(a))
    {
        for(i=0,c=0,s=1;i<strlen(a);i++){
            if((a[i]>='a' && a[i]<='z')||(a[i]>='A'&&a[i]<='z')){
                if(s==1){
                    c++;
                }
                s=0;
            }
            else{
                s=1;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}


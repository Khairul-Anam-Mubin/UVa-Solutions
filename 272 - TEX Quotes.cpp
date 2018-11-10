/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[10000];
    int i,c=1;

    while(scanf(" %[^\n]",&str)==1)
    {
        //gets(str);
        for(i=0;str[i];i++){
            if(str[i]=='"'){
                if(c%2)
                    printf("``");
                else
                    printf("''");
                c++;
                }
            else
                printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}

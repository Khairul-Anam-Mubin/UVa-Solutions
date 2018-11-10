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
    int i,maxi;

    ///freopen("output.txt","w",stdout);

    while(scanf(" %[^\n]",&str)==1)
    {
        vector <int> v(125,0);

        for(i=0;str[i];i++)
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
                v[str[i]]++;

        maxi=0;
        for(i=65;i<=122;i++)
            if(v[i]>maxi)
                maxi=v[i];

        for(i=65;i<=122;i++)
            if(v[i]==maxi)
                printf("%c",i);

        printf(" %d\n",maxi);
    }
    return 0;
}

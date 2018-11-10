/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int lenstr(char x[]);

int main()
{
    char s[100];
    unsigned long long i,n,x,sum;
    while(scanf("%s",s) && s[0]!='0')
    {
        n=lenstr(s);
        x=n;
        for(i=0,sum=0;i<n;i++,x--){
            sum+=((s[i]-'0')*(pow(2,x)-1));
        }
        printf("%llu\n",sum);
    }
    return 0;
}
int lenstr(char x[]) //x=putting the characters
{
    int i=0;
    while(x[i])
        i++;
    return i;
}

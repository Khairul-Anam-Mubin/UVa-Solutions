/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int lenstr(char x[]);
void revstr(char str[]);

int main()
{
    char s[110],r[110];
    int g,n,len,i,j,c;
    while(scanf("%d",&g) && g!=0)
    {
        scanf("%s",s);
        len=lenstr(s);
        n=len/g;
        c=n;
        //printf("%d\n",n);
        for(i=0,j=0;i<len;i++,j++){
            if(i<c){
                r[j]=s[i];
            }
            else{
                r[j]='\0';
                j=-1;
                i--;
                c=c+n;
                revstr(r);
                printf("%s",r);
            }
        }
        r[j]='\0';
        revstr(r);
        printf("%s\n",r);
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
void revstr(char str[]) //str=putting the string to reverse
{
    int i,r,len;
    char temp;
    len=lenstr(str);
    for(i = 0, r = len-1; i < r; ++i, --r){
        temp=str[i];
        str[i]=str[r];
        str[r]=temp;
    }
}

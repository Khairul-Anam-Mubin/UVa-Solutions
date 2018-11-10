/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include<bits/stdc++.h>

using namespace std;

void revstr(char s[]);

int main()
{
    char str[100000],s[100000];

    long int i,len,j;

    while(scanf(" %[^\n]",&str)==1)
    {
      len=strlen(str);

      for(i=0,j=0;i<=len;i++,j++){
            if(str[i]=='\0'){
                s[j]='\0';
                revstr(s);
                cout<<s<<endl;
            }
            else if(str[i]!=' '){
                s[j]=str[i];
            }
            else{
                s[j]='\0';
                revstr(s);
                cout<<s;
                cout<<" ";
                j=-1;

            }
        }
    }
    return 0;
}
void revstr(char s[])
{
    int i,r,len;

    len=strlen(s);
    for(i=0,r=len-1;i<r;i++,r--)
        swap(s[i],s[r]);
}

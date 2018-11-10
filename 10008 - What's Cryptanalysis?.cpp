/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int s[300];

int main()
{
    int len,i,j,t,n,maxi,c;
    char str[100001];

    scanf("%d",&t);

    while(t--)
    {
        scanf(" %[^\n]",&str);

        len=strlen(str);
        for(i=0;i<len;i++){
            if(str[i]>='a' && str[i]<='z'){

                str[i]=str[i]-32;
                s[str[i]]++;
            }
            else if(str[i]>='A' && str[i]<='Z')
                s[str[i]]++;
        }

    }
	maxi=0;
	for(i='A';i<='Z';i++){
        for(j='A';j<='Z';j++){
            if(s[j]>maxi){
                maxi=s[j];
                c=j;
            }
        }
        if(s[c]!=0)
            printf("%c %d\n",c,maxi);
		
		s[c]=0;
        maxi=0;
    }
    return 0;
}


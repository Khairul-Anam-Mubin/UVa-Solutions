/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int compstr(char str1[],char str2[]);

int main()
{
	char str[10000],str1[10000],s[]={"DONE"};
	int i,len,j,flag;

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);

	while(scanf(" %[^\n]",&str)==1)
	{
		if(compstr(str,s))
			break;

		for(i=0,j=0;str[i];i++){
			if(str[i]>='A' && str[i]<='Z')
				str[i]=str[i]+32;
			if(str[i]>='a' && str[i]<='z'){
				str1[j]=str[i];
				j++;
			}
		}
		str1[j]='\0';
		len=strlen(str1);
		flag=1;
		for(i=0;i<len;i++){
			if(str1[i]!=str1[len-1-i]){
				flag=0;
				break;
			}
		}
		if(flag)
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}
	return 0;
}
int compstr(char str1[],char str2[])
{
    int len1,len2,i;
    len1=strlen(str1);
    len2=strlen(str2);
    if(len1!=len2)
        return 0;
    else
        for(i=0;i<len1;i++)
            if(str1[i]!=str2[i])
                return 0;
    return 1;
}

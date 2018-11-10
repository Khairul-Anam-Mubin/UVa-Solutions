/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	char str[500],a[300];
	int len,i;
	a['A']=2,a['B']=2,a['C']=2,a['D']=3,a['E']=3,a['F']=3,a['G']=4,a['H']=4,a['I']=4,
	a['J']=5,a['K']=5,a['L']=5,a['M']=6,a['N']=6,a['O']=6,a['P']=7,a['Q']=7,a['R']=7,
	a['S']=7,a['T']=8,a['U']=8,a['V']=8,a['W']=9,a['X']=9,a['Y']=9,a['Z']=9;

	while(gets(str))
	{
		len=strlen(str);
		for(i=0;i<len;i++){
			if(str[i]=='1' || str[i]=='0' || str[i]=='-')
				printf("%c",str[i]);
			else{
				printf("%d",a[str[i]]);
			}
		}
		printf("\n");
	}
	return 0;
}

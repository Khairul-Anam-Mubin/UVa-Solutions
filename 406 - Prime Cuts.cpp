/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <stdio.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define mx 1000

bool prime[mx+1];
int cp[mx+1];

void sieve();

int main()
{
	sieve();
	int i,n,c,cnt,num,ulm,llm,j;

	while(cin >> n)
	{
		cin >> c;
		cout << n << " " << c << ": ";

		for(i=1,j=1,cnt=0;i<=n;i++){
			if(prime[i]==0){
				cp[j]=i;
				j++;
				cnt++;
			}
		}
		if(cnt%2){
			num=(2*c)-1;
			ulm=((cnt/2)+1)-(c-1);
			llm=(cnt/2)+c;
		}
		else{
			num=2*c;
			ulm=1+(cnt/2)-c;
			llm=(cnt/2)+c;
		}
		if(num>cnt){
			for(i=1;i<=cnt;i++){
				if(i==cnt)
					cout << cp[i] << "\n";
				else
					cout << cp[i] << " ";
			}
			cout << "\n";
			continue;
		}
		for(i=ulm;i<=llm;i++){
			if(i==llm)
				cout << cp[i] << "\n";
			else
				cout << cp[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
void sieve()
{
	int sq,i,j;
	sq=sqrt(mx);

	for(i=2;i<=sq;i++){
		if(prime[i]==0){
			for(j=i*i;j<=mx;j+=i){
				prime[j]=1;
			}
		}
	}
}

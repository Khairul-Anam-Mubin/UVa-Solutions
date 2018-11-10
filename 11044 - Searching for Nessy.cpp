/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long int t,n,m;
	
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		printf("%ld\n",((n/3)*(m/3)));
	}
	return 0;
}


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
#include <stack>
#include <algorithm>

#define pb push_back
const double pi = acos(-1.0);
//typedef long long ll;
//typedef unsigned long long ull;

using namespace std;


int main()
{
	int tc=0,t,n,sq;

	cin >> t;

	while(t--)
	{
		cin >> n;

		sq=(int)sqrt(n);
		int cnt=0,a[10];
		
		for(int i=2;i<=sq && cnt!=2;i++){
			if(n%i==0){
				a[cnt]=i;
				cnt++;
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n",++tc,n,a[0],n/a[0],a[1],n/a[1]);
	}
	return 0;
}

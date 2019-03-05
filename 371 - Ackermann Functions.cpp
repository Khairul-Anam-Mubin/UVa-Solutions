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
typedef long long ll;
//typedef unsigned long long ull;

using namespace std;


int main()
{
	ll L,R,n,mx,cnt,x;

	while(cin >> L >> R)
	{
		if(L==0 && R==0)
			break;
		if(L>R){
			swap(L,R);
		}
		mx=0;
		for(ll i=L;i<=R;i++){
			if(i==1)
				cnt=3;
			else
			{
				n=i;
				cnt=0;
				while(n!=1){
					if(n%2)
						n=3*n+1;
					else
						n/=2;
					cnt++;
				}	
			}
			if(cnt > mx){
				mx=cnt;
				x=i;
			}
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",L,R,x,mx);
	}
	return 0;
}

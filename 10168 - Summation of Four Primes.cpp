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

#define mx 10000000

bool prime[mx+1];

void sieve();
void next_two(int n);

int main()
{
	sieve();
	int n;
	while(cin >> n)
	{
		if(n<8){
			cout << "Impossible.\n"; 
			continue;
		}
		if(n%2){
			cout << "2 3 ";
			n-=5;
			next_two(n);
		}
		else{
			cout << "2 2 ";
			n-=4;
			next_two(n);
		}
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
void next_two(int n)
{
	int i;
	for(i=2;i<=n;i++){
		if(prime[i]==0 && prime[n-i]==0){
			cout << i << " " << n-i << "\n";
			break;
		}
	}
}

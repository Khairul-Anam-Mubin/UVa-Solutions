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

#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)

using namespace std;

#define mx 99999999

bool prime[mx+1];

void sieve();

int main()
{
	sieve();

	//fileout;

	long int n,x,i,flag;
	while(cin >> n)
	{
		flag=0;
		if(n==1 || n==2 || n==3 || n==4){
			flag=0;
		}
		else if(n%2){
			if(prime[n-2]==0){
				flag=1;
				i=2;
			}
		}
		else{
			x=(n/2)-1;
			for( i=x;i>=2;i--){
				if(prime[i]==0 && prime[n-i]==0){
					flag=1;
					break;
				}
			}
		}	
		if(flag){
			printf("%ld is the sum of %ld and %ld.\n",n,i,n-i);
		}
		else{
			printf("%ld is not the sum of two primes!\n",n);
		}
	}
	return 0;
}
void sieve()
{
	long int sq,i,j;
	sq=sqrt(mx);

	for(i=2;i<=sq;i++){
		if(prime[i]==0){
			for(j=i*i;j<=mx;j+=i){
				prime[j]=1;
			}
		}
	}
}

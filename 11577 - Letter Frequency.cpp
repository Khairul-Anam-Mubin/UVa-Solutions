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
	getchar();


	while(t--)
	{
		string str;
		getline(cin,str);
		
		vector <int> v(30,0);
		
		int len=(int)str.size();

		for(int i=0; i<len; i++){
			if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') ){
				v[(int)tolower(str[i])-96]++;
			}
		}
		int mx=*max_element(v.begin(),v.end());

		for(int i=1; i<=26;i++){
			if(v[i]==mx){
				printf("%c",i+96);
			}
		}
		cout << "\n";
	}
	return 0;
}

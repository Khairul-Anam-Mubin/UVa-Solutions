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
    string ss1,ss2;

    vector <int> A,B;

    while(getline(cin,ss1))
    {
    	getline(cin,ss2);

    	string s1,s2;

    	//to convert a stringline to string and convert the string to integer..
    	istringstream is1(ss1);
    	while(is1>>s1){
    		stringstream geek(s1);
    		int x=0;
    		geek >> x;
    		A.pb(x);
    	}

    	//to convert a stringline to string and convert the string to integer..
    	istringstream is2(ss2);
    	while(is2>>s2){
    		stringstream geek(s2);
    		int x=0;
    		geek >> x;
    		B.pb(x);
    	}

    	//for(int i=0;i<(int)A.size();i++){
    	//	cout << A[i] << endl;
    	//}
    	//for(int i=0;i<(int)B.size();i++){
    	//	cout << B[i] << endl;
    	//}

    	int asz=(int)A.size(),bsz=(int)B.size();
    	//cout << asz << endl << bsz << endl;
    	int a=0,b=0;

    	for(int i=0 ; i<asz; i++){
    		for(int j=0;j<bsz ; j++){
    			if(A[i]==B[j]){
    				a++;
    			}
    		}
    	}
    	for(int i=0 ; i<bsz ; i++){
    		for(int j=0; j<asz ; j++){
    			if(B[i]==A[j]){
    				b++;
    			}
    		}
    	}
    	
    	if(asz==a && asz<bsz){
    		cout << "A is a proper subset of B\n";
    	}
    	else if(bsz==b && asz>bsz){
    		cout << "B is a proper subset of A\n";
    	}
    	else if(asz == bsz && asz==a && bsz==b){
    		cout << "A equals B\n";
    	}
    	else if(a==0 && b==0){
    		cout << "A and B are disjoint\n";
    	}
    	else{
    		cout << "I'm confused!\n";
    	}
    	
    	A.clear();
    	B.clear();
    	is1.clear();
    	is2.clear();
    }
    return 0;
}

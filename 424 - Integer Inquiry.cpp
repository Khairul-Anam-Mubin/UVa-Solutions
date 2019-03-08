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

string BigintSum(string str1,string str2);

int main()
{
    string a,b,sum;
    int i=1;
    
    while(cin >> a)
    {
        if(a.size() == 1 && a[0] == '0')
            break;
        if(i==1)
            sum=a;
        else{
            sum=BigintSum(a,sum);
        }
        i++;
    }
    cout << sum << "\n";

    return 0;
}
string BigintSum(string str1,string str2)
{
    if(str1.size() < str2.size())
        swap(str1,str2);
    
    int len1=(int)str1.size(); 
    int len2=(int)str2.size();
    int n=len2;
    int carry=0;
    string sum;

    for(int i=len1-1, j=len2-1; i>=0 ; i--, j--){
        int x;
        if(n){
            x = str1[i] - '0' + str2[j] - '0' + carry;
            n--;
        }
        else{
            x = str1[i] - '0' + carry;
        }
        carry=x/10;
        x=x%10;
        sum.push_back(x+'0');
    }
    if(carry)
        sum.push_back(carry+'0');
    reverse(sum.begin(),sum.end());

    return sum;
}

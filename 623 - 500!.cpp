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
string BigintProd(string str1,string str2);

int main()
{
    int n;
    string factorial;

    map <int,string> mp;

    mp[0]= "1";
    mp[1]= "1";
    mp[2]= "2";

    for(int i=3;i<=1001;i++){
        int x=i;
        ostringstream str1;
        str1 << x;
        string geek = str1.str();            
        mp[i]=BigintProd(mp[i-1],geek);
    }

    while(cin >> n)
    {
        cout << n << "!\n";
        cout << mp[n] << "\n";
    }

    return 0;
}
string BigintProd(string str1,string str2)
{
    if(str1.size() < str2.size())
        swap(str1,str2);
    
    int len1=(int)str1.size(); 
    int len2=(int)str2.size();
    int carry=0,cnt=1;
    string prod,pro;

    for(int i=len2-1; i>=0; i--){
        carry=0;
        for(int j=len1-1; j>=0; j--){
            int x = (str2[i] - '0') * (str1[j] - '0') + carry;
            carry=x/10;
            x=x%10;
            prod.push_back(x+'0');
        }
        if(carry)
            prod.push_back(carry+'0');
        reverse(prod.begin(),prod.end());
        if(cnt==1){
            pro=prod;
            cnt++;
            prod.clear();
        }
        else{
            pro=BigintSum(pro,prod);
            prod.clear();
        }
        for(int k=len2-1;k>=i;k--){
            prod.push_back('0');
        }
    }
    //return "0" if any multiply apply with 0
    if(pro[0]=='0' && pro.size()>1)
        pro="0";
    return pro;
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

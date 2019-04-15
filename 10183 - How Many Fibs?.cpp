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
#include <queue>
#include <stack>
#include <algorithm>

#define pb      push_back
#define Sqr(n)  (n*n)
#define Sort(v) sort(v.begin(),v.end())
#define Mxe(v)  *max_element(v.begin(),v.end())
#define Mne(v)  *min_element(v.begin(),v.end())
#define Fin     freopen("input.txt","r",stdin)
#define Fout    freopen("output.txt","w",stdout)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1000000007

//Code starts from here......

string BigintSum(string str1,string str2);
string BigintProd(string str1,string str2);

int cmp(string s1 ,string s2)
{
    int len1 = s1.size();
    int len2 =  s2.size();
    if(len1 != len2){
        return len1-len2;
    }
    for(int i = 0 ; i < len1 ; i++){
        if(s1[i] > s2[i])
            return 1;
        else if(s1[i] < s2[i])
            return -1;
    }
    return 0;
}

int main()
{
    Fout;
    map <int,string> mp;

    mp[1] = "1";
    mp[2] = "2";

    int i ;
    for( i = 3 ; true ; i++){
        mp[i] = BigintSum(mp[i-1],mp[i-2]);
        if(mp[i].size() >= 101)
            break;
    }

    string a , b;
    while(cin >> a >> b)
    {
        if(a == "0" && b == "0")
            break;

        int cnt1 = 0, cnt2 = 0;
        int endd , start;
        for(int j = 0 ; j < i ; j++){
            int tmp = cmp(mp[j],a);
            if(tmp >= 0){
                start = j;
                break;
            }
        }
        for(int j = 0 ; j < i ; j++){
            int tmp = cmp(mp[j],b);
            if(tmp >= 0){
                endd = j;
                if(tmp)
                    endd--;
                break;
            }
        }
        cout << endd - start+1 << "\n";        //cout << cnt1-cnt2 << "\n";
    }
    return 0;
}
//take to string as numbers and returns the product of these two numbers to strings

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

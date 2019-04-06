#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string dectohex(string str)
{
    if(str.size() == 1 && str[0] == '0'){
        return "0x0";
    }
    stringstream geek(str);
    int x = 0; geek >> x;

    str.clear();
    str = "0x";
    vector <int> v;
    while(x){
        int rem = x % 16;
        v.push_back(rem);
        x /= 16;
    }
    for(int i = v.size()-1 ; i >= 0 ; i--){
        if(v[i] < 10) str.push_back(v[i] + '0');
        else
            str.push_back(char(v[i] + 55));
    }
    return str;
}
int hextodec(string str)
{
    int len = str.size();
    string ss;

    for(int i = 2 ; i < len ; i++)
        ss.push_back(str[i]);

    len = ss.size();
    int p = len-1;
    int sum = 0;
    for(int i = 0 ; i < len ; i++ ,p--){
        if(ss[i] >= '0' && ss[i] <= '9')
            sum += (pow(16,p)*(ss[i] - '0'));
        else
            sum+= (pow(16,p)*(ss[i] - 55));
    }

    return sum;
}
int main()
{
    string str;
    while(cin >> str)
    {
        if(str[0] == '-')
            break;
        if(str[0] == '0' && str[1] == 'x')
            cout << hextodec(str) << "\n";
        else
            cout << dectohex(str) << "\n";
    }
    return 0;
}

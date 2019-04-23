#include <bits/stdc++.h>

using namespace std;

bool isalpha(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}
int digits(int x)
{
    int cnt = 0;
    while(x){
        x /= 10;
        cnt++;
    }
    return cnt;
}
int chtodig(char ch)
{
    return (ch-'0');
}
bool issim(char ch)
{
    string str = "!,.:;? ";
    int len = str.size();
    for(int i = 0 ; i < len ; i++)
        if(str[i] == ch)
            return true;
    return false;
}

int main()
{
    string str ;
    while(getline(cin,str))
    {
        string ss = "";
        string temp;
        int len = str.size();

        for(int i = 0 ; i < len ; i++){
            if(isalpha(str[i]) || issim(str[i])){
                int letr = str[i];
                int sz = digits(letr);
                for(int i = 0 ; i < sz ; i++){
                    temp.push_back((letr % 10) + '0');
                    letr /= 10;
                }
                reverse(temp.begin(),temp.end());
                ss = ss + temp;
                temp.clear();
            }

        }
        reverse(ss.begin(),ss.end());
        int x ;
        if(ss.size() == 0){
            reverse(str.begin(),str.end());
            for(int i = 0 ; i < len-1 ; i++){
                x = chtodig(str[i]) * 10 + chtodig(str[i+1]);
                if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || issim(x)){
                    ss.push_back((char)x);
                    i++;
                }
                else{
                    x = x * 10 + chtodig(str[i+2]);
                    ss.push_back((char)x);
                    i += 2 ;
                }
            }
        }
        cout << ss << "\n";
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);

    string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    ///Here using two \\ cz single \ will not work as like as single %
    
	string str;
    char ch=' ';
    int i,j;

    while(getline(cin,str))
    {
        for(i=0;i<str.size();i++){
            if(str[i]=='`' || str[i]=='A' || str[i]=='Q' || str[i]=='Z')
                continue;
            if(str[i]==ch){
                cout << ch;
                continue;
            }
            for(j=0;j<key.size();j++){
                if(str[i]==key[j]){
                    cout << key[j-1];
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}

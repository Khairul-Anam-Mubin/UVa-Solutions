#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc = 0;
    string str;
    while(cin >> str)
    {
        int qury;
        cin >> qury;
        cout << "Case " << ++tc << ":\n";
        while(qury--){
            int i , j; cin >> i >> j;
            if(i > j) swap(i,j);
            char flag = str[i];
            int yes = 1;
            for( i = i ; i <= j ; i++){
                if(flag != str[i]){
                    yes = 0;
                    break;
                }
            }
            if(yes) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}

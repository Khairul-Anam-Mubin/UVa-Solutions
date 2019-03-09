#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;
    while(n--)
    {
        string str1,str2;
        cin >> str1 >> str2;

        int flag = 1;
        
        if(str1 == str2)
            flag= 1;
        else{
            if(str1.size() != str2.size())
                flag = 0;
            else{
                for(int i=0;i<(int)str1.size();i++){
                    if(str1[i]!=str2[i]){
                        if((str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u') && (str2[i]=='a'||str2[i]=='e'||str2[i]=='i'||str2[i]=='o'||str2[i]=='u')){

                        }
                        else{
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

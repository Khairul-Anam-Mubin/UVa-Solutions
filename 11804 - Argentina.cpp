#include <bits/stdc++.h>

using namespace std;

struct node{
    int atk,dfns;
    string name ;
};
node pl[15];

void Swap(int i , int j)
{
    node temp ;
    temp = pl[i];
    pl[i] = pl[j];
    pl[j] = temp;
}

int main()
{
    //freopen("output.txt","w",stdout);
    int tc ,t = 0;
    cin >> tc ;

    while(tc--)
    {
        for(int i = 0 ; i < 10 ; i++)
            cin >> pl[i].name >> pl[i].atk >> pl[i].dfns;

        printf("Case %d:\n",++t);

        for(int i = 0 ; i < 10 ; i++)
            for(int j = i+1 ; j < 10 ; j++)
                if(pl[i].atk > pl[j].atk)
                    Swap(i,j);
                else if(pl[i].atk == pl[j].atk)
                    if(pl[i].dfns < pl[j].dfns)
                        Swap(i,j);
                    else if(pl[i].dfns == pl[j].dfns)
                        if(lexicographical_compare(pl[i].name.begin(),pl[i].name.end(),pl[j].name.begin(),pl[j].name.end()))
                             Swap(i,j);

        set <string> st1,st2;
        set <string> :: iterator it ;
        for(int i = 0 ; i < 5 ; i++)
            st1.insert(pl[i].name);
        for(int j = 5 ; j < 10 ; j++)
            st2.insert(pl[j].name);
        int i ;
        for(i = 0 , it = st2.begin() ; it != st2.end() ; it++ , i++){
            if(i == 0){
                cout << "(" << *it ;
                continue;
            }
            if(i == 4){
                cout << ", " << *it << ")\n";
                continue;
            }
            cout << ", " << *it;
        }
        for(i = 5 , it = st1.begin() ; it != st1.end() ; it++ , i++){
            if(i == 5){
                cout << "(" << *it ;
                continue;
            }
            if(i == 9){
                cout << ", " << *it << ")\n";
                continue;
            }
            cout << ", " << *it;
        }
    }

    return 0;
}

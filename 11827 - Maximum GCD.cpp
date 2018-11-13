/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept.of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[1000];
    int t,i,r,j,c,gcd;
    vector <int> v;

    //freopen("output.txt","w",stdout);

    scanf("%d",&t);

    while(t--)
    {
        scanf(" %[^\n]",&str);

        for(i=0,r=0,c=0;str[i]!='\0';i++){
            if(str[i]!=' '){
                r=r*10+(str[i]-48);
                c++;
            }
            else{
                if(c>0){
                    v.push_back(r);
                    r=0;
                    c=0;
                }
            }
        }
        gcd=0;

        if(c)
            v.push_back(r);

        for(i=0;i<v.size()-1;i++)
            for(j=i+1;j<v.size();j++)
                gcd = max(gcd,__gcd(v[i],v[j]));

         printf("%d\n",gcd);

        v.clear();
    }
    return 0;
}

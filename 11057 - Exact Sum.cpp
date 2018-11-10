/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

int main()
{
	///freopen("output.txt","w",stdout);
    long int n,x,bc,i,j,b1,b2,mini;
	
    while(scanf("%ld",&n)==1)
    {
        vector <int> v;
        while(n--){
            scanf("%ld",&x);
            v.push_back(x);
        }
        scanf("%ld",&bc);
        mini=1000001;
        for(i=0;i<v.size()-1;i++){
            for(j=i;j<v.size();j++){
                if(v[i]+v[j]==bc){
                    if(abs(v[i]-v[j])<mini){
                        mini=abs(v[i]-v[j]);
                        if(v[i]>v[j]){
                            b1=v[j];
                            b2=v[i];
                        }
                        else{
                            b1=v[i];
                            b2=v[j];
                        }
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %ld and %ld.\n\n",b1,b2);
    }
    return 0;
}

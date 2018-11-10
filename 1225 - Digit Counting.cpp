/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	///freopen("output.txt","w",stdout);
   
   int n,t,i,x;
   while(scanf("%d",&t)==1)
   {
      while(t--){
          vector <int> v(10,0);
          scanf("%d",&n);
          for(i=1;i<=n;i++){
              x=i;
              while(x){
                  v[x%10]++;
                  x/=10;
                }
            }
            for(i=0;i<9;i++)
                printf("%d ",v[i]);
            printf("%d\n",v[i]);
        }
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int y,a,i,temp,b;
    
	while(scanf("%ld",&y)==1 && y>=0)
    {
        a=0;
        b=0;
        temp=0;
        for(i=0;i<=y;i++){
            temp=(a+b)+1;
            a=b;
            b=temp;
        }
        cout<<a<<" "<<temp<<endl;
    }
    return 0;
}

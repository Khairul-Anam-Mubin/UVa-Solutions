/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

vector <int> v(Max+1,1);
long int twin[Max];

void sieve();
void twinpr();

int main()
{
    long int n;
    sieve();
    while(cin >> n)
    {
        printf("(%ld, %ld)\n",twin[n],twin[n]+2);
    }

    return 0;
}
void sieve()
{
    long int i,j,N;

    N=sqrt(Max);
    v[0]=0;
    v[1]=0;

    for(i=2;i<=N;i++)
        if(v[i])
            for(j=i*i;j<Max;j+=i)
                v[j]=0;
    twinpr();
}
void twinpr()
{
    long int i,j=1;
    for(i=3;i<Max;i++)
        if(v[i]==1 && v[i+2]==1)
            twin[j++]=i;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[1000];
    int a,b,c,d,e,k,n,i,flag,x=0;

    while(scanf("%s",s)==1)
    {
        if(x!=0){
            printf("\n");
        }
        x=1;
        a=0;
        b=0;
        c=0;
        d=0;
        e=0;
        k=0;
        flag=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            a=a*10+(s[i]-'0');
            a=a%4;
            b=b*10+(s[i]-'0');
            b=b%100;
            c=c*10+(s[i]-'0');
            c=c%400;
            d=d*10+(s[i]-'0');
            d=d%15;
            e=e*10+(s[i]-'0');
            e=e%55;
        }
        if((a==0 && b!=0)||(c==0 && b==0)){
            cout<<"This is leap year."<<endl;
            flag=1;
            k=1;
        }
        if(d==0){
            cout<<"This is huluculu festival year."<<endl;
            flag=1;
        }
        if(k==1){
            if(e==0){
                cout<<"This is bulukulu festival year."<<endl;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"This is an ordinary year."<<endl;
        }
    }
    return 0;
}

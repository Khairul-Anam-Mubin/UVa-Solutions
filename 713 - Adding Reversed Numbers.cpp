/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

void BigIntSum(int len,int bl,char a[],char b[],char sum[]);

int main()
{
    char a[300],b[300],sum[300];
    int t,i,al,bl,s,k,len,n,m;
    
	scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        
        al=strlen(a);
        bl=strlen(b);
        len=(al<bl)?bl:al;
        if(al>=bl){
            BigIntSum(len,bl,a,b,sum);
        }
        else{
            BigIntSum(len,al,b,a,sum);
        }
        n=strlen(sum);
        for(i=0,m=0;i<n;i++){
            if(m==0 && sum[i]=='0'){

            }
            else{
                printf("%c",sum[i]);
                m=1;
            }
        }
        printf("\n");
    }
    return 0;
}
void BigIntSum(int len,int bl,char a[],char b[],char sum[])
{
    int k,i,s,m,j,n,l,z=0;
    for(i=0,l=0,m=0,k=0;i<len;l++,i++){
        if(i>=bl)
            s=k+(a[i]-'0');
        else
            s=k+(a[i]-'0')+(b[i]-'0');
        if(s<10){
            sum[l]=s+'0';
            k=0;
            m=1;
        }
        else{
            j=s%10;
            k=s/10;
            sum[l]=j+'0';
            m=1;
        }
        if(i==len-1 && k!=0){
            sum[l+1]=k+'0';
            m=1;
            sum[l+2]='\0';
            z=1;
        }
    }
    if(z==0)
        sum[len]='\0';

}

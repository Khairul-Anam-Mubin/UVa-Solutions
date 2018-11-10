/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

void uptolow(char a[]);
int countstr(char a[]);
int sumdigit(int x);

int main()
{
    char a[30],b[30];
    double love;
    int i,x,y;
    while(gets(a))
    {
      gets(b);
      
      ptolow(a);
      uptolow(b);
      x=countstr(a);
      y=countstr(b);
      x=sumdigit(x);
      y=sumdigit(y);
      if(x<y)
          love=((x*1.0)/y)*100;
      else
          love=((y*1.0)/x)*100;
      printf("%0.2lf %%\n",love);
    }
    return 0;
}
void uptolow(char a[])
{
    int i;
    for(i=0;a[i];i++)
            if(a[i]>='A' && a[i]<='Z')
                a[i]=a[i]+32;
}
int countstr(char a[])
{
    int i,suma;
    for(i=0,suma=0;a[i];i++)
            if(a[i]>='a' && a[i]<='z')
                suma+=(a[i]-96);
    return suma;
}
int sumdigit(int x)
{
    int n,s;
    n=x;
    while(1){
        s=0;
        while(x!=0){
            s=s+(x%10);
            x=x/10;
        }
        if(s>9){
            x=s;
        }
        else{
            return s;
        }
    }
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int t=0,n,age,cdays,cmonth,cyear,cd,bd,byear,bmonth,bdays;
    char s[15],a[15];
    scanf("%ld",&n);
    while(n--)
    {
        scanf("%s",s);
        cdays=(s[0]-48)*10+(s[1]-48);
        cmonth=(s[3]-48)*10+(s[4]-48);
        cyear=(s[6]-48)*1000+(s[7]-48)*100+(s[8]-48)*10+(s[9]-48);
        cd=cdays+(cmonth*30)+(cyear*365);
        scanf("%s",a);
        bdays=(a[0]-48)*10+(a[1]-48);
        bmonth=(a[3]-48)*10+(a[4]-48);
        byear=(a[6]-48)*1000+(a[7]-48)*100+(a[8]-48)*10+(a[9]-48);
        bd=bdays+(bmonth*30)+(byear*365);
        age=((cd-bd)/365);
        if(cd==bd)
            printf("Case #%ld: 0\n",++t);
        else if(cd<bd)
            printf("Case #%ld: Invalid birth date\n",++t);
        else if(age>130)
            printf("Case #%ld: Check birth date\n",++t);
        else
            printf("Case #%ld: %ld\n",++t,age);
    }
    return 0;
}

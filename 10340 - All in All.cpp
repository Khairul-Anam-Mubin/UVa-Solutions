/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,len1,len2,flag,c;
    char str1[100000],str2[100000];

    while(scanf("%s%s",str1,str2)==2)
    {
        len1=strlen(str1);
        len2=strlen(str2);

        for(i=0,flag=1,c=0,j=0;i<len1;i++){
            for(;j<len2;j++){
                if(str1[i]==str2[j]){
                   flag=0;
                   break;
                }
            }
            if(flag==1)
                break;
            else{
                flag=1;
                c++;
                j++;
            }
        }
        //cout << c << endl;
        if(c==len1 && flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

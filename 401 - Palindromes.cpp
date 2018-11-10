/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[100];
    int i,len,r,pm,mr;

    while(scanf(" %[^\n]",&str)==1)
    {
        len=strlen(str);

        for(i=0,pm=0,r=len-1;i<len;i++,r--)
            if(str[i]==str[r])
                pm++;

        for(mr=0,i=0,r=len-1;i<len;i++,r--){
            if(str[i]=='A' && str[r]=='A'||str[i]=='E' && str[r]=='3'||
               str[i]=='H' && str[r]=='H'||str[i]=='I' && str[r]=='I'||
               str[i]=='J' && str[r]=='L'||str[i]=='L' && str[r]=='J'||
               str[i]=='M' && str[r]=='M'||str[i]=='O' && str[r]=='O'||
               str[i]=='S' && str[r]=='2'||str[i]=='T' && str[r]=='T'||
               str[i]=='U' && str[r]=='U'||str[i]=='V' && str[r]=='V'||
               str[i]=='W' && str[r]=='W'||str[i]=='X' && str[r]=='X'||
               str[i]=='Y' && str[r]=='Y'||str[i]=='Z' && str[r]=='5'||
               str[i]=='1' && str[r]=='1'||str[i]=='2' && str[r]=='S'||
               str[i]=='3' && str[r]=='E'||str[i]=='5' && str[r]=='Z'||
               str[i]=='8' && str[r]=='8')
                mr++;
        }
        if(pm==len && mr==len)
            printf("%s -- is a mirrored palindrome.\n",str);
        else if(mr==len)
            printf("%s -- is a mirrored string.\n",str);
        else if(pm==len)
            printf("%s -- is a regular palindrome.\n",str);
        else
            printf("%s -- is not a palindrome.\n",str);
        printf("\n");
    }
    return 0;
}

/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
   char str[10000];
   int i;

   while(scanf(" %[^\n]",&str)==1)
   {
       for(i=0;i<strlen(str);i++)
            printf("%c",str[i]-7);
		
        printf("\n");
   }
   return 0;
}

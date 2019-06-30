#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc , t = 0;
    scanf("%d",&tc);
    while(tc--) {
        char str[1010];
        scanf("%s",str);
        int len = strlen(str);
        int ind[10];
        for(int i = 0 ; i < 10 ; i++){
            ind[i] = 0;
        }
        int sum = 0;
        for(int i = 0; i < len ; i++) {
            int x = str[i] - '0';
            sum += x ;
            ind[x]++ ;
        }
        int k = 1;
        while(true){
            int cnt = 0;
            for(int j = 1 ; j < 10 ; j++) {
                if(sum && ind[j] && ((sum - j ) % 3 == 0)){
                    sum -= j;
                    ind[j]--;
                    k++;
                    cnt = 1;
                }

            }
            if(cnt == 0 ||(sum % 3 != 0) || (sum == 0))
                break;
        }
        if(k % 2)
            printf("Case %d: T\n",++t);
        else
            printf("Case %d: S\n",++t);
    }
    return 0;
}

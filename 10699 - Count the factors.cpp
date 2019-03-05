#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,x;

	while(cin >> n)
	{
		if(n==0)
			break;
		x=n;
		int sq=(int)sqrt(n)+1;
		int cnt=0;

		for(int i=2;i<sq;i++){
			if(x%i==0){
				cnt++;
				while(x%i==0){
					x/=i;
				}
			}
			if(x==1){
				break;
			}
		}
		if(x!=1){
			cnt++;
		}
		//cout << cnt << "\n";
		cout << n << " : " << cnt << "\n";
	}


	return 0;
}

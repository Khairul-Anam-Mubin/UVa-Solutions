#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc,n,p,a[110],check[3655];

	cin >> tc;

	while(tc--)
	{
		cin >> n >> p;

		for(int i=0;i<p;i++){
			cin >> a[i];
		}
		for(int i=1;i<=3650;i++){
			check[i]=0;
		}
		for(int i=0;i<p;i++){
			for(int j=1;j<=n;j++){
				if(j%7!=0 && j%7!=6){
					if(j%a[i]==0){
						check[j]=1;
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(check[i]==1){
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}

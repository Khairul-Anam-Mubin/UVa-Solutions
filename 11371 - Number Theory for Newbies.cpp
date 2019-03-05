#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n,mn,mx,x,r,cnt;
	vector <ll> v;
	
	while(cin >> n)
	{
		x=n;

		while(x){
			r=x%10;
			v.push_back(r);
			x/=10;
		}
		sort(v.begin(),v.end());
		mx=mn=cnt=0;

		for(int i=(int)v.size()-1; i>=0 ; i--){
			mx=mx*10+v[i];
			if(v[i]==0){
				cnt++;
			}
		}
		int flag=1;
		for(int i=0;i<(int)v.size();i++){
			if(v[i]!=0 && flag){
				flag=0;
				mn=mn*10+v[i];
				for(int j=0 ;j<i;j++){
					mn=mn*10;
				}
			}
			else{
				mn=mn*10+v[i];
			}
		}

		cout << mx << " - " << mn << " = " << mx-mn << " = " << "9 * " << (mx-mn)/9 << "\n";
		//cout << mx << " " << mn << endl;
		v.clear();
	}

	return 0;
}

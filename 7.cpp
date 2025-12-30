#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1005];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2 and ans+a[i]<=a[1]){
			ans+=a[i];
		}
	}
	for(int i=1;i<n;i++) {
		ll o,p;cin>>o>>p;
	}
	cout<<ans;
	
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
ll a[100005],b[100005],c[100005];
using namespace std;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]*a[i+1]-a[i]*a[i];
	}
	for(int i=1;i<n;i++){
		c[i]=c[i-1]+b[i];
	}
	ll ans=1e18;
	for(int i=1;i<=n-m+1;i++){
		ans=min(ans,c[i+m-2]-c[i-1]);
	}
	cout<<ans<<"\n";
	
	return 0;
}

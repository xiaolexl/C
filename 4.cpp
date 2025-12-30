#include <bits/stdc++.h>
#define ll long long
ll a[100005];
using namespace std;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t;cin>>t;
	while(t--){
		ll a,b,c,k;cin>>a>>b>>c>>k;
		for(int i=1;i<=k;i++){
			ll na,nb,nc;
			na=(b+c)/2;
			nb=(a+c)/2;
			nc=(a+b)/2;
			a=na;b=nb;c=nc;
		}
		cout<<a<<" "<<b<<" "<<c<<" "<<"\n";
	}
	return 0;
}

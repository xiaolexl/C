#include <bits/stdc++.h>
#define ll long long
ll a[100005];
using namespace std;
const ll MOD = 1e9 + 7;
ll ans=0;ll n;
void dfs2(vector<ll> v){
	if(v.size()==1){
		ans+=v[0];
		ans%=MOD;
		return;
	}
	ll it=v[v.size()-1];
	v.pop_back();
	v[0]+=it;
	dfs2(v);
	v[0]-=it;
	v[0]-=it;
	dfs2(v);
}
void dfs(vector<ll> v,ll x){
	if(x>n) {
		dfs2(v);
		return;
	}
	v.push_back(a[x]);
	dfs(v,x+1);
	v.pop_back();
	
	if(v.size()){
		ll tp=v[v.size()-1];
		v[v.size()-1]^=a[x];
		dfs(v,x+1);
		v[v.size()-1];
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	vector<ll> d;
		ll now=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];now^=a[i];
	}
	if(n<=13){
		dfs(d,1);
	}else{
		ll op=2;
		ans+=now;
		now^=a[n];
		ll tp=0;
		for(int i=n-1;i>=1;i--){
			ans+=now*op;
			ans%=MOD;
			now^=a[i];
			op*=3;
			op%=MOD;
		}
		ans%=MOD;
		ans+=MOD;
		ans%=MOD;
	}
	cout<<ans<<"\n";
	return 0;
}

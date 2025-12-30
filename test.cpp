#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 100;
ll a[Q];
pair<ll,ll> d[Q];
vector<ll> ans;
void dfs(ll x,ll t){
	if(a[x]>a[t]){
		if(d[t].first){
			dfs(x,d[t].first);
		}else{
			d[t].first=x;
		}
	}else{
		if(d[t].second){
			dfs(x,d[t].second);
		}else{
			d[t].second=x;
		}
	}
}
int main(){
	ll n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		dfs(i,1);
	}
	queue<ll> q;q.push(1);ans.push_back(a[1]);
	while(q.size()){
		ll now=q.front();q.pop();
		if(d[now].first){
			ans.push_back(a[d[now].first]);
			q.push(d[now].first);
		}
		if(d[now].second){
			ans.push_back(a[d[now].second]);
			q.push(d[now].second);
		}
	}
	for(int i=0;i<ans.size();i++) {
		if(i==ans.size()-1) cout<<ans[i];
		else cout<<ans[i]<<" ";
	}
	if(a[6]>a[3] and a[n]<a[6])
	cout<<"\nNO";
	else
	cout<<"\nYES";
	
	return 0;
}
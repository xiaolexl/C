#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Q = 2e5 + 9;
const ll MOD = 998244353;
ll a[Q],b[Q],cnt[Q];
vector<pair<ll,ll>> d[Q];
map<ll,ll> mp;
void solve(){
    ll n;cin>>n;
    for (ll i = 1; i <= n; i++) cin>>a[i],mp[a[i]]++;
    for (ll i = 1; i <= n; i++) cin>>b[i],d[i].push_back({0,0});
    ll pre=a[1];ll l=1;
    for (ll i = 2; i <= n; i++){
      if(a[i]!=pre){
        d[pre].push_back({l,i-1});
        pre=a[i];l=i;
      }
    }
    d[pre].push_back({l,n});
    for (ll i = 1; i <= n; i++) d[i].push_back({n+1,n+1});
    for (ll i = 1; i <= n; i++)
    {
      // cout<<i<<"\n";
      // for(auto j:d[i]) cout<<j.first<<" "<<j.second<<"\n";
      ll ans=0;
      ll pre=1;
      for (ll j = 0; j < d[i].size(); j++)
      {
        if(d[i][j].second-d[i][j].first+1<=b[i]){
          continue;
        }
        ans+=d[i][j].first-1-pre+1;
        if((d[i][j].first-1-pre+1)!=0)
        ans+=b[i];
        pre=d[i][j].second+1;
      }
        ans+=n-pre+1;
        if((n-pre+1)!=0)
        ans+=b[i];
        cnt[i]=ans;
    }
    if(mp.size()!=1)
    {
      ll it=1;
      while(a[it]==a[1]) it++;
      if(it-1<=b[a[1]])
      cnt[a[1]]-=it-1;
      it=n;
      while(a[it]==a[n]) it--;
      if(n-it<=b[a[n]])
      cnt[a[n]]-=n-it;
    }
    
    for (ll i = 1; i <= n; i++)
    {
      cout<<cnt[i]<<" ";
    }
    
    


    
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll _ = 1;//cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
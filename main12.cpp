#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 1e5 + 9;
ll a[Q];
void slove(){
  ll n,k;cin>>n>>k;
  string ans="";
  priority_queue<ll> q;
  ll cnt=k;
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
    ans+="0";
    k/=2;
    if(a[i]%2) cnt++;
    if(a[i]==1){
      q.push(i);
    }
  }
  ll tp=1;
  while(q.size()){
    if(tp%2){
      ans[q.top()]='1';
    }else{
      ans[q.top()]='0';
    }
    q.pop();
    tp++;
  }
  if(cnt%2==0){
    for (ll i = 0; i < n; i++)
    {
      if(a[i]>1) ans[i]='0';
    }
    
  }else{
    for (ll i = 0; i < n; i++)
    {
      if(a[i]>1) ans[i]='1';
    }
  }
  for (int i = ans.size() - 1; i >= 0; i--)
  {
    cout<<ans[i];
  }
  
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  ll _ = 1;//cin>>_;
  while(_--) slove();
  return 0;
}
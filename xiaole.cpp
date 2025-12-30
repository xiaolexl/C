#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 2e6 + 9;
ll f[Q];//线段树
ll a[Q];//原数组
ll v[Q];//该区间需要加的数
inline void jltree(ll k,ll l,ll r){//根据a数组建树f 区间和线段树
    v[k]=0;
    if(l==r){
        f[k]=a[l];
        return;
    }
    ll m=(l+r)/2;
    jltree(2*k,l,m);
    jltree(2*k+1,m+1,r);
    f[k] = f[2*k]+f[2*k+1];
}
ll qjsum(ll k,ll l,ll r,ll x,ll y,ll p){//区间和(x到y) 默认p=0
    if(x>y) return 0;
    p+=v[k];
    if(x==l and y==r){
        return p*(r-l+1)+f[k];
    }
    ll m=(l+r)/2;
    if(m>=x and m<y){
        return qjsum(2*k,l,m,x,m,p)+qjsum(2*k+1,m+1,r,m+1,y,p);
    }
    if(y<=m){
        return qjsum(2*k,l,m,x,y,p);
    }else{
        return qjsum(2*k+1,m+1,r,x,y,p);
    }
}
inline void insert(ll k,ll l,ll r,ll x,ll y,ll z){//区间修改(x,y)都加上z
    if(x>y) return;
    if(l==x and r==y){
        v[k]+=z;
        return;
    }
    f[k] += (y-x+1)*z;
    ll m=(l+r)/2;
    if(m>=x and m<y){
        insert(2*k,l,m,x,m,z);
        insert(2*k+1,m+1,r,m+1,y,z);
        return;
    }
    if(y<=m){
        insert(2*k,l,m,x,y,z);
        return;
    }else{
        insert(2*k+1,m+1,r,x,y,z);
        return;
    }
}
inline void jltree2(ll k,ll l,ll r){//根据a数组建树f 区间大值线段树
    if(l==r){
        f[k]=a[l];
        return;
    }
    ll m=(l+r)/2;
    jltree2(2*k,l,m);
    jltree2(2*k+1,m+1,r);
    f[k] = max(f[2*k],f[2*k+1]);
}
ll qjmax(ll k,ll l,ll r,ll x,ll y){//区间最大值查询
    if(l==x and r==y){
        return f[k];
    }
    ll m=(l+r)>>1;
    if(x<=m and y>m){
        return max(qjmax(k<<1,l,m,x,m),qjmax(k<<1|1,m+1,r,m+1,y));
    }
    if(x<=m){
        return qjmax(k<<1,l,m,x,y);
    }
    if(y>m){
        return qjmax(k<<1|1,m+1,r,x,y);
    }
    return -2e18;
}
void solve(){
    ll n,m;cin>>n>>m;
    for (ll i = 1; i <= n; i++){
        cin>>a[i];
    }
    jltree2(1,1,n);
    for (ll i = 0; i < m; i++)
    {
        ll l,r;cin>>l>>r;
        cout<<qjmax(1,1,n,l,r)<<"\n";
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

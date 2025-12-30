#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Q = 2e6 + 9;
const ll MOD = 998244353;
ll a[Q][10];
void solve(){
    string s;cin>>s;s=" "+s;
    ll ans=0;
    for(int i=1;i<s.size();i++){
        a[i][(s[i]-'0')]++;
        for(int j=0;j<10;j++){
            if(a[i-1][j]){
                ll now=j+(s[i]-'0');
                while(now>=10){
                    ll newnow=now/10+now%10;
                    now=newnow;
                }
                a[i][now]+=a[i-1][j];
            }
            ans+=a[i][j]*j;
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<=s.size();i++)
        for(int j=0;j<10;j++) 
         a[i][j]=0;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll _ = 1;cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
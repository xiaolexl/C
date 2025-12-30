#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    ll ans=0;
    unordered_map<string,int> mp;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        cnt+=s.size();
        while(s.size()){
            ans+=mp[s];
            ans%=MOD;
            mp[s]++;
            s.pop_back();
        }
    }
    cout<<(ans*2%MOD+cnt%MOD)%MOD<<"\n";
    return 0;
}
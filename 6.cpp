#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s[2];cin>>s[0]>>s[1];
	ll n=s[0].size();
	s[0]=" "+s[0];s[1]=" "+s[1];
	ll ans=0;
	ll l=0,r=0;
	for(int i=1;i<=n;i++){
		if((s[0][i]=='#' || s[1][i]=='#') && l==0){
			l=i;
		}
		if((s[0][i]=='#' || s[1][i]=='#')){
			r=i;
		}
	}
	ll cnt=-1;
	if(s[0][l]=='.' && s[1][l]=='#') cnt=1;
	if(s[1][l]=='.' && s[0][l]=='#') cnt=0;
	
	for(int i=l+1;i<=r;i++){
		if(s[0][i]=='.' && s[1][i]=='.'){
			ans++;
		}else if(s[0][i]=='#' && s[1][i]=='.'){
			if(cnt==1){
				cnt=-1;
				ans++;
			}else{
				cnt=0;
			}
		}else if(s[0][i]=='.' && s[1][i]=='#'){
			if(cnt==0){
				cnt=-1;
				ans++;
			}else{
				cnt=1;
			}
		}else{
			cnt=-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

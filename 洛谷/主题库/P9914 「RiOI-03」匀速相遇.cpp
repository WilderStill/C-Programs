#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x,ans;
unordered_map<ll,ll> mp;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){scanf("%lld",&x);mp[x*i]++;}
	for(ll i=1;i<=m;i++){scanf("%lld",&x);if(x)ans+=mp[x*i];}
	printf("%lld",ans);
}

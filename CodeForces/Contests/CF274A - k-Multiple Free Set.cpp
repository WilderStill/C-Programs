#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1145141],ans;
map<ll,bool>mp;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		if(!mp[a[i]])
			mp[a[i]*k]=1,ans++;
	printf("%lld",ans);
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
queue<ll>q;
string pi="3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067";
int main()
{
	for(ll i=1,x;i<=100;i++)
		x=(ll)(pi[i-1]-48),q.push(x);
	scanf("%lld",&t);
	while(t--)
	{
	    ll ans=1,n=q.front();
		q.pop();
	    for(ll i=1,tmp;i<=n;i++)
		{
			scanf("%lld",&tmp);
			ans*=tmp;
		}
	    printf("%lld\n",ans);
	}
	return 0;
}

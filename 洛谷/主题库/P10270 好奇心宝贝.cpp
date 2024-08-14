#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
bool fg=0;
set<char>s[4145];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
		{
			char ch;
			cin>>ch;
			s[i+j-1].insert(ch);
		}
	for(ll i=1;i<=n+m-1;++i)
		if(s[i].size()>1)
		{
			printf("%lld\n",i-1);fg=1;break;
		}
	if(!fg)printf("%lld\n",n+m-1);
	return 0;
}

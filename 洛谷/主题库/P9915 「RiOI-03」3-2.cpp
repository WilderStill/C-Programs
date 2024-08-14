#include<bits/stdc++.h>
#define ull unsigned long long
#define mod 998244353
using namespace std;
ull n,q,ans;
ull qpow(ull a,ull b)
{
	ull res=1;
	while(b)
	{
		if(b&1)res=(res*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	return res%mod;
}
int main()
{
	scanf("%lld%lld",&n,&q);
	while(q--)
	{
		ull x,y;
		scanf("%lld%lld",&x,&y);
		if(y>64)
		{
			printf("%lld\n",qpow(2,n)-1);
			continue;
		}
		x++,y++;
		ans=(qpow(2,y)-1+mod)%mod;	
		bool fg=((x-1)>>(y-1)&1)?1:0;//1?0?
		int tmp=qpow(2,y-1);
		while(y<n&&(fg?(((x-1)>>(y))&1):(!(((x-1)>>(y))&1))))
		{				
			tmp=(tmp*2)%mod;
			ans=(ans+tmp)%mod;
			y++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

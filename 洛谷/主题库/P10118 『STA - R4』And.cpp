#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll m;
int main()
{
	scanf("%d%lld",&T,&m);
	while(T--)
	{
		register ll a,b;
		scanf("%lld%lld",&a,&b);
		a-=b*2;
		if((a&b)||a<0){puts("0");continue;}
		register ll cnt=0,n=0;
		for(register int i=59;i>=0;--i)
		{
			register ll t=1ll<<i;
			if(!n)n=t&a;
			else cnt+=((a&t))?1:0;
		}
		cnt=1ll<<cnt;
		cnt%=m;
		n%=m;
		printf("%lld\n",cnt*n%m);
	}
	return 0;
}

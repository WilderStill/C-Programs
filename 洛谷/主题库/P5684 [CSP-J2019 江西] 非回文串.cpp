#include<bits/stdc++.h>
#define M 1000100
#define ll long long
using namespace std;
const ll p=1000000007;
ll n,frac[M],inv[M],buk[M],tmp,ans=1;
char s[M];
ll qpow(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)res=x*res%p;
        x=x*x%p;
        y>>=1;
    }
    return res;
}
void init()
{
    frac[0]=1;
    for(ll i=1;i<M;++i)frac[i]=frac[i-1]*i%p;
    inv[M-1]=qpow(frac[M-1],p-2);
    for(ll i=M-1;i>1;--i)inv[i-1]=inv[i]*i%p;
}
int main()
{
	scanf("%lld%s",&n,s+1);
	init();
	bool fg=0;
	for(int i=1;i<=n;++i)++buk[s[i]-'a'+1]; 
	for(int i=1;i<=26;++i)
		if(buk[i]&1) 
		{
			if(fg) 
			{
				printf("%lld",frac[n]);
				return 0;
			} 
			fg=1;
			tmp=buk[i]--;
		}
	for(int i=1;i<=26;++i) 
	{
		if(!buk[i])continue;
		(ans*=frac[buk[i]]*inv[buk[i]/2]%p)%=p;
	}
	(ans*=frac[n/2])%=p; 
	if(fg)(ans*=tmp)%=p; 
	ans=(frac[n]-ans+p)%p;
	printf("%lld",ans);
	return 0;
} 

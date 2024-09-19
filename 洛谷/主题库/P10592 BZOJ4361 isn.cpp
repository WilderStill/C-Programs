#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define ll long long
#define M 2010
using namespace std;
const ll mod=1000000007;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
ll n,a[M],tp[M],tr[M],g[M],f[M][M],frac[M],ans;
inline void add(ll x,ll v)
{
	for(ll i=x;i<=n;i+=lowbit(i))(tr[i]+=v)%=mod;
}
inline ll query(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i))(res+=tr[i])%=mod;
	return res;
}
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)a[i]=tp[i]=read();
	sort(tp,tp+n+1);
	for(ll i=0;i<=n;++i)a[i]=lower_bound(tp,tp+n+1,a[i])-tp+1;
	f[0][0]=1;
	for(ll j=1;j<=n;++j)
	{
		memset(tr,0,sizeof tr);
		for(ll i=1;i<=n;++i)
		{
			add(a[i-1],f[i-1][j-1]);
			f[i][j]=query(a[i]);
			g[j]=(g[j]+f[i][j])%mod;
		}
	}
	frac[0]=1;
	for(ll i=1;i<=n;++i)frac[i]=frac[i-1]*i%mod;
	for(ll i=1;i<=n;++i)
	{
		(ans+=g[i]*frac[n-i]%mod)%=mod;
		ans=(ans-g[i+1]*frac[n-i-1]%mod*(i+1)%mod+mod)%mod;
	}
	write(ans);
	return 0;
}

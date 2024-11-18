#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
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
inline void file()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
}
ll val[250010],sum[250010],f[250010],q[250010],hd,tl;
int main()
{
	//file();
	ll n=read(),k=read();
	for(int i=1;i<=n;++i)val[i]=read(),sum[i]=sum[i-1]+max(val[i],0ll);
	f[1]=val[1],q[hd=tl=1]=0;
	for(int i=2;i<=n;++i)
	{
		while(q[hd]<i-k)++hd;
		if(hd<=tl)f[i]=val[i]+val[i-1]+f[q[hd]]+sum[i-2]-sum[q[hd]];
		while(hd<=tl&&f[i-1]-sum[i-1]>=f[q[tl]]-sum[q[tl]])--tl;
		q[++tl]=i-1;
	}
	ll ans=sum[k];
	for(int i=1;i<=n;++i)ans=max(ans,f[i]+sum[min(i+k-1,n)]-sum[i]);
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline ll readl()
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
int n,q;
ll p,w[100010];
unordered_map<ll,ll>mp;
inline ll qmod(ll x,ll mod)
{
	return x<mod?x:(x%mod+mod);
}
inline ll Eulerphi(ll mod)
{
	ll tmp=mod,ans=1;
	for(ll i=2;i*i<=tmp;++i)
	{
		if(tmp%i)continue;
		ans*=i-1;
		tmp/=i;
		while(!(tmp%i))ans*=i,tmp/=i;
	}
	if(tmp>1)ans*=(tmp-1);
	return ans;
}
inline ll qpow(ll x,ll y,ll mod)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=qmod(res*x,mod);
		x=qmod(x*x,mod);
		y>>=1;
	}
	return res;
}
inline ll f(int l,int r,ll mod)
{
	if(l==r||mod==1)return qmod(w[l],mod);
	return qpow(w[l],f(l+1,r,mp[mod]),mod);
}
int main()
{
	n=read(),p=readl();
	ll t=p;
	while(t^1)mp[t]=Eulerphi(t),t=mp[t];
	for(int i=1;i<=n;++i)w[i]=readl();
	q=read();
	for(int i=1;i<=q;++i)
	{
		int l=read(),r=read();
		write(f(l,r,p)%p);
		putchar('\n');
	}
	return 0;
}


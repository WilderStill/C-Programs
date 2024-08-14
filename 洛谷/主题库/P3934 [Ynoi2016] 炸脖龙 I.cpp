#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
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
ll p,w[500010],Primetot,Prime[20000100],phi[20000100];
bool isPrime[20000100];
struct node
{
    ll val;
    bool fg;
    node(ll _v=0,bool _fg=0):val(_v),fg(_fg){} 
};
void Eulerphi(ll n)
{
	for(ll i=2;i<=n;++i)
	{
		if(!isPrime[i])Prime[++Primetot]=i,phi[i]=i-1;
		for(ll j=1;j<=Primetot&&i*Prime[j]<=n;++j)
		{
			isPrime[Prime[j]*i]=1;
			if(i%Prime[j]==0){phi[i*Prime[j]]=phi[i]*Prime[j];break;}
			phi[i*Prime[j]]=phi[i]*(Prime[j]-1);
		}
	}
}
inline void modify(ll x,ll v)
{
	for(ll i=x;i<=n;i+=lowbit(i))w[i]+=v;
}
inline ll query(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i))res+=w[i];
	return res;
}
inline node qpow(ll x,ll y,ll mod)
{
	node res={1,0};
    while(y)
	{
		if(x>=mod)
		{
	        x%=mod;
	        res.fg=1;
	    }
        if(y&1)res.val=res.val*x;
        if(res.val>=mod)
		{ 
            res.fg=1;
            res.val%=mod;
        }
        y>>=1;
        x=x*x;
    }
    return res;
}
node f(int l,int r,ll mod)
{
	ll tp=query(l);
	if(mod==1)return{0,1};
	if(tp==1)return{1,0};
	if(l==r)return tp<mod?(node){tp,0}:(node){tp%mod,1};
	ll syh=phi[mod];
    node res=f(l+1,r,syh);
    if(res.fg)res.val+=syh;
    return qpow(tp,res.val,mod);
}
int main()
{
	Eulerphi(20000010);
	n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		ll x=readl();
		modify(i,x);
		modify(i+1,-x);
	}
	for(int i=1;i<=q;++i)
	{
		int op=read(),l=read(),r=read();
		if(op==1)
		{
			ll x=readl();
			modify(l,x);
			modify(r+1,-x);
		}
		else
		{
			p=readl();
			auto ans=f(l,r,p);
			write(ans.val);
			putchar('\n');
		}
	}
	return 0;
}

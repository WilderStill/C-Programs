#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define ll long long
using namespace std;
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
ll n,q,last,tr1[1000010],tr2[1000010];
void add1(ll x,ll val)
{
	for(ll i=x;i<=n;i+=lowbit(i))tr1[i]+=val;
}
void add2(ll x,ll val)
{
	for(ll i=x;i<=n;i+=lowbit(i))tr2[i]+=val;
}
ll query1(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i))res+=tr1[i];
	return res;
}
ll query2(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i))res+=tr2[i];
	return res;
}
int main()
{
	n=read(),q=read();
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		add1(i,x-last);
		add2(i,(i-1)*(x-last));
		last=x;
	}
	while(q--)
	{
		ll op=read();
		if(op==1)
		{
			ll l=read(),r=read(),v=read();	
			add1(l,v);
			add1(r+1,-v);
			add2(l,v*(l-1));
			add2(r+1,-v*r);
		}
		if(op==2)
		{
			ll l=read(),r=read();
			write(r*query1(r)-query2(r)-(l-1)*query1(l-1)+query2(l-1));
			puts("");	
		}
	}
	return 0;	
}

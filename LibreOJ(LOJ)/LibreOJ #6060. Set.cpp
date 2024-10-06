#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Dg=63;
inline int read()
{
    int x=0,f=1;
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
inline ll readl()
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
ll S,num[110],tp[100010];
bool fg;
inline void insert(ll x)
{
	for(int i=Dg;~i;--i)
		if(!(S&(1ll<<i))&&(x&(1ll<<i)))
		{
			if(!num[i]){num[i]=x;return;}
            x^=num[i];
		}
	for(int i=Dg;~i;--i)
		if((S&(1ll<<i))&&(x&(1ll<<i)))
		{
			if(!num[i]){num[i]=x;return;}
            x^=num[i];
		}
}
inline ll query()
{
	ll res=0;
	for(int i=Dg;~i;--i)
		if(!(S&(1ll<<i))&&!(res&(1ll<<i)))
            res^=num[i];
	for(int i=Dg;~i;--i)
		if((S&(1ll<<i))&&(res&(1ll<<i)))
			res^=num[i];
    return res;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)S^=(tp[i]=readl());
	for(int i=1;i<=n;++i)insert(tp[i]);
	write(query());
    return 0;
}
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
ll num[110],tp[110];
bool fg;
inline void insert(ll x)
{
	for(int i=Dg;~i;--i)
		if(x&(1ll<<i))
		{
			if(!num[i]){num[i]=x;return;}
            x^=num[i];
		}
	fg=1;
}
inline ll querymax()
{
	ll res=0;
	for(int i=Dg;~i;--i)res=max(res,res^num[i]);
    return res;
}
inline ll querymin()
{
    if(fg)return 0;
    for(int i=0;i<=Dg;++i)
        if(num[i])return num[i];
}
inline ll query(ll k)
{
	ll res=0;
	int cnt=0;
	k-=fg;
	if(!k)return 0;
	for(int i=0;i<=Dg;++i)
	{
		for(int j=i-1;~j;--j)
			if(num[i]&(1ll<<j))num[i]^=num[j];
		if(num[i])tp[cnt++]=num[i];
	}
	if(k>=(1ll<<cnt))return -1;
    for(int i=0;i<cnt;++i)
        if(k&(1ll<<i))res^=tp[i];
    return res;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)insert(readl());
    int m=read();
    for(int i=1;i<=m;++i)
    {
    	ll k=readl();
		write(query(k));
		puts("");
	}
    return 0;
}

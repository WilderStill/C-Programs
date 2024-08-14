#include<bits/stdc++.h>
#define ll long long
#define M 1000100
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
ll val[M<<2],n,q,s,t,last,ans;
ll tsyh(ll x){return (x>=0)?-x*s:-x*t;}
int main()
{
	//freopen("wind.in","r",stdin);
	//freopen("wind.out","w",stdout);
	n=read(),q=read(),s=read(),t=read();
	for(int i=0,dg;i<=n;++i)
	{
		dg=read();
		val[i]=dg-last;
		last=dg;
		ans+=tsyh(val[i]);
	}
	for(int i=1;i<=q;++i)
	{
		ll l=read(),r=read(),x=read();
		ans-=tsyh(val[l]);
		val[l]+=x;
		ans+=tsyh(val[l]);
		if(r<n)
		{
			ans-=tsyh(val[r+1]);
			val[r+1]-=x;
			ans+=tsyh(val[r+1]);
		}
		write(ans);puts("");
	}
	return 0;
}

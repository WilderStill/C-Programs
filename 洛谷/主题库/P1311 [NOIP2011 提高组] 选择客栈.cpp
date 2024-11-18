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
ll sum[200010],cnt[200010],suf[200010],syh,ans;
int main()
{
	ll n=read(),k=read(),p=read();
	for(int i=1;i<=n;++i)
	{
		ll col=read(),cost=read();
		if(cost<=p)syh=i;
    	if(syh>=suf[col])sum[col]=cnt[col];
    	ans+=sum[col],suf[col]=i,++cnt[col];
	}
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

#include<bits/stdc++.h>
#define ll long long
#define ld long double
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
ll sum[5000010],cnt[5000010],f[5000010],q[5000010],hd=1,tl=0,n,m,maxx,ans=998244353;
ll X(ll i1)
{
	return cnt[i1];
}
ll Y(ll i1)
{
	return f[i1]+sum[i1];
}
ld k(ll i1,ll i2)
{
	if(X(i1)==X(i2))return Y(i2)>Y(i1)?1e9:-1e9;
	return (ld)((ld)(Y(i2)-Y(i1)))/((ld)(X(i2)-X(i1)));
}
int main()
{
	n=read(),m=read();
	for(ll i=1,x;i<=n;++i)x=read(),maxx=max(x,maxx),++cnt[x],sum[x]+=x;
	for(ll i=1;i<m+maxx;++i)cnt[i]+=cnt[i-1],sum[i]+=sum[i-1];
	for(ll i=0;i<m;++i)f[i]=cnt[i]*i-sum[i];
	q[++tl]=0;
	for(ll i=m;i<m+maxx;++i)
	{
		while(hd<tl&&k(q[hd],q[hd+1])<=i)++hd;
        f[i]=f[q[hd]]+(cnt[i]-cnt[q[hd]])*i-sum[i]+sum[q[hd]];
        while(hd<tl&&k(q[tl-1],q[tl])>=k(q[tl-1],i-m+1))--tl;
        q[++tl]=i-m+1;
	}
	for(ll i=maxx;i<m+maxx;++i)ans=min(ans,f[i]);
	write(ans);
	return 0;
}

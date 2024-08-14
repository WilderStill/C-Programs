#include<bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
ll n,K,sum[100010],pos=0,hd=1,tl=1,q[100010],cnt[100010],f[100010];
ll X(int i1)
{
	return sum[i1];
}
ll Y(int i1)
{
	return f[i1]-(sum[i1]<<1)+sum[i1]*sum[i1];
}
ld kk(int i1,int i2)
{
	return (ld)((ld)(Y(i1)-Y(i2)))/((ld)(X(i1)-X(i2)));
}
bool check(ll x)
{
	hd=1,tl=1;
	q[1]=0;
    for(int i=1;i<=n;++i)
    {
    	while(hd<tl&&kk(q[hd],q[hd+1])<=(sum[i]<<1))++hd;
        f[i]=f[q[hd]]+(sum[i]-sum[q[hd]]+1)*(sum[i]-sum[q[hd]]+1)+x;
        cnt[i]=cnt[q[hd]]+1;
        while(hd<tl&&kk(q[tl-1],q[tl])>=kk(q[tl],i))--tl;
        q[++tl]=i;
    }
    return cnt[n]>=K;
}
int main()
{
	n=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+read();
	}
	ll l=0,r=1e18,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	mid=l-1;
	check(mid);
	printf("%lld",f[n]-K*mid);
    return 0;
}

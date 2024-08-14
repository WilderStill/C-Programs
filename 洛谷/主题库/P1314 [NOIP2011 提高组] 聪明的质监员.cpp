#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define M 200010
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
inline void write(int x)
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
int n,m,maxw=-INF,minw=INF,w[M],v[M],l[M],r[M];
ll s,sum,ans=1e18,sumw[M],sumv[M];
bool check(int x)
{
	ll syh=0;
	sum=0;
	memset(sumw,0,sizeof sumw);
	memset(sumv,0,sizeof sumv);
	for(int i=1;i<=n;++i)
	{
		if(w[i]>=x)sumw[i]=sumw[i-1]+1,sumv[i]=sumv[i-1]+v[i];
		else sumw[i]=sumw[i-1],sumv[i]=sumv[i-1];
	}
	for(int i=1;i<=m;++i)
		syh+=(sumw[r[i]]-sumw[l[i]-1])*(sumv[r[i]]-sumv[l[i]-1]);
	sum=syh-s>0?syh-s:s-syh;
	return syh>s;
}
int main()
{
	n=read(),m=read(),s=readl();
	for(int i=1;i<=n;++i)
	{
		w[i]=read(),v[i]=read();
		maxw=max(maxw,w[i]);
		minw=min(minw,w[i]);
	}
	for(int i=1;i<=m;++i)
		l[i]=read(),r[i]=read();
	int L=minw-1,R=maxw+1;
	while(L<R)
	{
		int mid=(L+R)>>1;
		if(check(mid))L=mid+1;
		else R=mid;
		ans=min(ans,sum);
	}
	write(ans);
    return 0;
}

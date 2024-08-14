#include <bits/stdc++.h>
#define M 114514
#define uque(x) unique(x+1,x+n+1)-x-1
#define lowbit(x) (x&-x)
using namespace std;
struct line
{
	int x,y,rx,tp;
}l[M*3];
struct point
{
	int x,y;
}p[M];
int n,x[M],y[M],xd[M],yd[M],lcnt,c[M];
bool cmpp1(point a,point b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmpp2(point a,point b)
{
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
bool cmpl(line a,line b)
{
	if(a.y==b.y) return a.tp<b.tp;
	return a.y<b.y;
}
void modify(int x,int v)
{
	for(;x<=M;x+=lowbit(x))c[x]+=v;
}
int query(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		xd[i]=x[i];
		yd[i]=y[i];
	}
	sort(xd+1,xd+n+1);
	sort(yd+1,yd+n+1);
	int fxd=uque(xd),fyd=uque(yd);
	for(int i=1;i<=n;i++)
	{
		x[i]=lower_bound(xd+1,xd+fxd+1,x[i])-xd;
		y[i]=lower_bound(yd+1,yd+fyd+1,y[i])-yd;
	}
	for(int i = 1;i <= n;i++)
	{
		p[i].x=x[i];
		p[i].y=y[i];
	}
	sort(p+1,p+n+1,cmpp2);
	for(int i=1;i<n;i++)
	{
		if(p[i].y==p[i+1].y)
		{
			l[++lcnt].x=p[i].x;
			l[lcnt].y=p[i].y;
			l[lcnt].rx=p[i+1].x;
			l[lcnt].tp=0;
		}
	}
	sort(p+1,p+n+1,cmpp1);
	for(int i=1;i<n;i++)
	{
		if(p[i].x==p[i+1].x)
		{
			l[++lcnt].x=p[i].x;
			l[lcnt].y=p[i].y;
			l[lcnt].rx=0;
			l[lcnt].tp=1;
			l[++lcnt].x=p[i].x;
			l[lcnt].y=p[i+1].y;
			l[lcnt].rx=0;
			l[lcnt].tp=-1;
		}
	}
	sort(l+1,l+lcnt+1,cmpl);
	int ans=n;
	for(int i=1;i<=lcnt;i++)
	{
		if(l[i].tp) modify(l[i].x,l[i].tp);
		else ans+=query(l[i].rx-1)-query(l[i].x);
	}
	printf("%d",ans);
	return 0;
}

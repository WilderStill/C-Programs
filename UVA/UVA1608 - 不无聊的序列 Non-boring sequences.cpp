#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
const int M=1000010;
struct Line{int l,r,h,mk;inline bool operator<(Line b){return h<b.h;}}ln[M];
int vl[M],tp[M],pre[M],nxt[M],top[M];
struct SegmentTree{ll cnt,len;}tr[M<<3];
inline void build(ll rt,ll l,ll r)
{
	tr[rt]={0,0};
	if(l==r)return;
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	return;
}
inline void update(ll rt,ll l,ll r){tr[rt].len=tr[rt].cnt?r-l+1:tr[lson].len+tr[rson].len;}
inline void modify(ll rt,ll posl,ll posr,ll l,ll r,ll mk)
{
	if(l>=posl&&r<=posr)
	{
		tr[rt].cnt+=mk;
		update(rt,l,r);
		return;
	}
	int mid=l+r>>1;
	if(posl<=mid)modify(lson,posl,posr,l,mid,mk);
	if(posr>mid)modify(rson,posl,posr,mid+1,r,mk);
	update(rt,l,r);
	return;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;++i)vl[i]=tp[i]=read();
		sort(tp+1,tp+n+1);
		int m=unique(tp+1,tp+n+1)-tp-1;
		for(int i=1;i<=n;++i)vl[i]=lower_bound(tp+1,tp+m+1,vl[i])-tp;
		for(int i=1;i<=m;++i)top[i]=0;
		for(int i=1;i<=n;++i)
		{
			pre[i]=top[vl[i]];
			top[vl[i]]=i;
		}
		for(int i=1;i<=m;++i)top[i]=n+1;
		for(int i=n;i;--i)
		{
			nxt[i]=top[vl[i]];
			top[vl[i]]=i;
		}
		for(int i=1;i<=n;++i)
		{
			int tx1=i,ty1=pre[i]+1,tx2=nxt[i]-1,ty2=i;
			ln[(i<<1)-1]=(Line){tx1,tx2,ty1,1};
			ln[(i<<1)]=(Line){tx1,tx2,ty2+1,-1};
		}
		build(1,1,n);
		sort(ln+1,ln+n*2+1);
		ll ans=0;
		int pos=1;
		for(int i=1;i<=n;++i)
		{
			while(pos<=2*n&&ln[pos].h<=i)modify(1,ln[pos].l,ln[pos].r,1,n,ln[pos].mk),++pos;
			ans+=tr[1].len;
		}
		puts(ans==(1ll+n)*n/2?"non-boring":"boring");
	}
	return 0;
}
/*
4
5
1 2 3 4 5
5
1 1 1 1 1
5
1 2 3 2 1
5
1 1 2 1 1
*/

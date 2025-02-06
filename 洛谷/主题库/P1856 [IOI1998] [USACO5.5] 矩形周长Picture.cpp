#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
typedef int ll; 
inline ll read()
{
	ll x=0,f=1;
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
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline char readdir()
{
	char ch=getchar();
	while(ch!='W'&&ch!='E'&&ch!='N'&&ch!='S')ch=getchar();
	return ch;
}
const int M=1000010;
ll x[M<<1];
struct Line{ll l,r,h;int mk;inline bool operator<(Line b){return h==b.h?mk>b.mk:h<b.h;}}ln[M<<1];
struct SegmentTree{int l,r;ll cnt,len,ck;bool cl,cr;}tr[M<<2];
inline void build(int rt,int l,int r)
{
	tr[rt]={l,r,0,0,0,0,0};
	if(l==r)return;
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	return;
}
inline void update(int rt)
{
	int l=tr[rt].l,r=tr[rt].r;
	if(tr[rt].cnt)
	{
		tr[rt].len=x[r+1]-x[l];
		tr[rt].cl=tr[rt].cr=1;
		tr[rt].ck=1;
	}
	else
	{
		tr[rt].len=tr[lson].len+tr[rson].len;
		tr[rt].cl=tr[lson].cl,tr[rt].cr=tr[rson].cr;
		tr[rt].ck=tr[lson].ck+tr[rson].ck;
		if(tr[lson].cr&&tr[rson].cl)--tr[rt].ck;
	}
}
inline void modify(int rt,ll posl,ll posr,int mk)
{
	int l=tr[rt].l,r=tr[rt].r;
	if(x[r+1]<=posl||posr<=x[l])return;
	if(posl<=x[l]&&x[r+1]<=posr)
	{
		tr[rt].cnt+=mk;
		update(rt);
		return;
	}
	modify(lson,posl,posr,mk);
	modify(rson,posl,posr,mk);
	update(rt);
	return;
}
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)
	{
		ll tx1=read(),ty1=read(),tx2=read(),ty2=read();
		x[(i<<1)-1]=tx1,ln[(i<<1)-1]=(Line){tx1,tx2,ty1,1};
		x[i<<1]=tx2,ln[i<<1]=(Line){tx1,tx2,ty2,-1};
	}
	n<<=1;
	sort(ln+1,ln+n+1),sort(x+1,x+n+1);
	int len=unique(x+1,x+n+1)-x-1;
	build(1,1,len-1);
	ll ans=0,pre=0;
	for(int i=1;i<n;++i)
	{
		modify(1,ln[i].l,ln[i].r,ln[i].mk);
		ans+=abs(pre-tr[1].len);
		pre=tr[1].len;
		ans+=2*tr[1].ck*(ln[i+1].h-ln[i].h);
	}
	ans+=ln[n].r-ln[n].l;
	write(ans);
	return 0;
}

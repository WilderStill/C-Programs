#include<bits/stdc++.h>
#define M 300010
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
char syh[M];
struct Segment_Tree
{
	int sum,tag;
}tr[M<<2];
int n,m;
void pushdown(int rt,int len)
{
	if(tr[rt].tag) 
	{
		tr[lson].tag^=1;
		tr[rson].tag^=1;
		tr[lson].sum=(len-(len>>1))-tr[lson].sum;
		tr[rson].sum=(len>>1)-tr[rson].sum;
		tr[rt].tag=0;
	}
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tr[rt].sum=syh[l]-'0';
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	tr[rt].sum=tr[lson].sum+tr[rson].sum;
}
void update(int rt,int nowl,int nowr,int l,int r)
{
	pushdown(rt,r-l+1);
	if(nowl<=l&&r<=nowr)
	{
		tr[rt].tag^=1;
		tr[rt].sum=r-l+1-tr[rt].sum;
		return;
	}
	int mid=(l+r)>>1;
	if(nowl<=mid)update(lson,nowl,nowr,l,mid);
	if(nowr>mid)update(rson,nowl,nowr,mid+1,r);
	tr[rt].sum=tr[lson].sum+tr[rson].sum;
}
int query(int rt,int nowl,int nowr,int l,int r)
{
	if(nowl<=l&&r<=nowr)return tr[rt].sum;
	int res=0,mid=(l+r)>>1;
	pushdown(rt,r-l+1);
	if(nowl<=mid)res+=query(lson,nowl,nowr,l,mid);
	if(nowr>mid)res+=query(rson,nowl,nowr,mid+1,r);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",syh+1);
	build(1,1,n);
	for(int i=1,op,x,y;i<=m;++i)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==0)update(1,x,y,1,n);
		else printf("%d\n",query(1,x,y,1,n));
	}
	return 0;
}

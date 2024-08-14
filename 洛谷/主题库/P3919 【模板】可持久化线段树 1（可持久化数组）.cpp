#include<bits/stdc++.h>
#define M 31451412
using namespace std;
int m,n,tot,rt[M],a[M];
struct Node
{
	int l,r,val;
}tree[M];
int newnode(int k)
{
	tree[++tot]=tree[k];
	return tot;
}
int build(int k,int l,int r)
{
	k=++tot;
	if(l==r)
	{
		tree[k].val=a[l];
		return tot;
	}
	int mid=(l+r)/2;
	tree[k].l=build(tree[k].l,l,mid);
	tree[k].r=build(tree[k].r,mid+1,r);
	return k;
}
int update(int k,int l,int r,int x,int val)
{
	k=newnode(k);
	if(l==r)tree[k].val=val;
	else
	{
		int mid=(l+r)/2;
		if(x<=mid)tree[k].l=update(tree[k].l,l,mid,x,val); 
		else tree[k].r=update(tree[k].r,mid+1,r,x,val);
	}
	return k;
}
int query(int k,int l,int r,int x)
{
	if(l==r)return tree[k].val;
	else
	{
		int mid=(l+r)/2;
		if(x<=mid)return query(tree[k].l,l,mid,x);
		else return query(tree[k].r,mid+1,r,x);;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	rt[0]=build(0,1,n);
	for(int i=1,v,op,val,nval;i<=m;i++)
	{
		scanf("%d%d%d",&v,&op,&val);
		if(op==1)
		{
			scanf("%d",&nval);
			rt[i]=update(rt[v],1,n,val,nval);
		}
		else
		{
			printf("%d\n",query(rt[v],1,n,val)); 
			rt[i]=rt[v];
		}
	}
}

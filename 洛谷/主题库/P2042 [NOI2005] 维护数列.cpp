#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define M 511451
#define INF 0x3f3f3f3f
using namespace std;
int n,m,top,stack_1[M],tot,rt;
struct node
{
	int key,size,to_rev,to_ms,ls,rs,val;
	ll max,s,l,r;
}tree[M];
void seg_rev(int k)
{
	if(!k) return;
	swap(tree[k].l,tree[k].r);
	swap(tree[k].ls,tree[k].rs);
	tree[k].to_rev^=1;
}
void pushup(int k)
{
	tree[k].size=tree[tree[k].ls].size+tree[tree[k].rs].size+1;
	tree[k].s=tree[tree[k].ls].s+tree[tree[k].rs].s+tree[k].val;
	tree[k].l=max(tree[tree[k].ls].l,max(0ll,tree[tree[k].ls].s+tree[k].val+tree[tree[k].rs].l));
	tree[k].r=max(tree[tree[k].rs].r,max(0ll,tree[tree[k].rs].s+tree[k].val+tree[tree[k].ls].r));
	tree[k].max=max((ll)tree[k].val,tree[tree[k].ls].r+tree[k].val+tree[tree[k].rs].l);
	if(tree[k].ls) tree[k].max=max(tree[k].max,tree[tree[k].ls].max);
	if(tree[k].rs) tree[k].max=max(tree[k].max,tree[tree[k].rs].max);
}
void pushdown(int k)
{
	if(tree[k].to_ms!=INF)
	{
		int c=tree[k].to_ms;
		if(tree[k].ls)
		{
			tree[tree[k].ls].to_ms=tree[tree[k].ls].val=c;
			tree[tree[k].ls].s=tree[tree[k].ls].size*c;
			tree[tree[k].ls].l=tree[tree[k].ls].r=max(0ll,tree[tree[k].ls].s);
			tree[tree[k].ls].max=max((ll)c,tree[tree[k].ls].s);
		}
		if(tree[k].rs)
		{
			tree[tree[k].rs].to_ms=tree[tree[k].rs].val=c;
			tree[tree[k].rs].s=tree[tree[k].rs].size*c;
			tree[tree[k].rs].l=tree[tree[k].rs].r=max(0ll,tree[tree[k].rs].s);
			tree[tree[k].rs].max=max((ll)c,tree[tree[k].rs].s);
		}
		tree[k].to_ms=INF;
	}
	if(tree[k].to_rev)
	{
		if(tree[k].ls)seg_rev(tree[k].ls);
		if(tree[k].rs)seg_rev(tree[k].rs);
		tree[k].to_rev=0;
	}
}
void splits(int k,int size,int &x,int &y)
{
	if(!k)
	{
		x=y=0;
		return;
	}
	pushdown(k);
	if(size<=tree[tree[k].ls].size)
	{
		y=k;
		splits(tree[y].ls,size,x,tree[y].ls);
		pushup(y);
	}
	else
	{
		x=k;
		splits(tree[x].rs,size-tree[tree[x].ls].size-1,tree[x].rs,y);
		pushup(x);
	}
	pushup(k);
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	if(tree[x].key<tree[y].key)
	{
		pushdown(x);
		tree[x].rs=merge(tree[x].rs,y);
		pushup(x);
		return x;
	}
	else
	{
		pushdown(y);
		tree[y].ls=merge(x,tree[y].ls);
		pushup(y);
		return y;
	}
}
int build(int k)
{
	int tmp=top?stack_1[top--]:++tot;
	tree[tmp].key=rand();
	tree[tmp].to_ms=INF;
	tree[tmp].to_rev=0;
	tree[tmp].ls=tree[tmp].rs=0;
	tree[tmp].max=tree[tmp].s=tree[tmp].val=k;
	tree[tmp].l=tree[tmp].r=max(k,0);
	tree[tmp].size=1;
	return tmp;
}
void del(ll k)
{
	if(tree[k].ls)del(tree[k].ls);
	if(tree[k].rs)del(tree[k].rs);
	stack_1[++top]=k;
}
int build(int l,int r)
{
	if(l==r)
	{
		int tmp;
		scanf("%intd",&tmp);
		return build(tmp);
	}
	int x=build(l,mid),y=build(mid+1,r);
	return merge(x,y);
}
void del(int l,int r)
{
	int x,y,z;
	splits(rt,r,x,z);
	splits(x,l-1,x,y);
	del(y);
	rt=merge(x,z);
}
ll query(int l,int r)
{
	int x,y,z;
	splits(rt,r,x,z);
	splits(x,l-1,x,y);
	ll res=tree[y].s;
	rt=merge(merge(x,y),z);
	return res;
}
void INSERT(int v1,int v2)
{
	int x,y;
	splits(rt,v1,x,y);
	rt=merge(merge(x,build(v1,v1+v2-1)),y);
}
void DELETE(int v1,int v2){del(v1,v1+v2-1);}
void REVERSE(int v1,int v2)
{
	int x,y,z;
	splits(rt,v1+v2-1,x,z);
	splits(x,v1-1,x,y);
	seg_rev(y);
	rt=merge(merge(x,y),z);
}
void MAKE_SAME(int v1,int v2,int v3)
{
	int x,y,z;
	splits(rt,v2+v1-1,x,z);
	splits(x,v1-1,x,y);
	tree[y].to_ms=tree[y].val=v3;
	tree[y].s=tree[y].size*v3;
	tree[y].l=tree[y].r=max(0ll,tree[y].s);
	tree[y].max=max((ll)v3,tree[y].s);
	rt=merge(merge(x,y),z);
}
void GET_SUM(int v1,int v2){printf("%lld\n",query(v1,v1+v2-1));}
void MAX_SUM(int v){printf("%lld\n",tree[v].max);}
int main()
{
	scanf("%d%d",&n,&m);
	rt=build(1,n);
	for(int i=1,v1,v2,v3;i<=m;i++)
	{
		string op;
		cin>>op;
		if(op=="INSERT")scanf("%d%d",&v1,&v2),INSERT(v1,v2);
		else if(op=="DELETE")scanf("%d%d",&v1,&v2),DELETE(v1,v2);
		else if(op=="REVERSE")scanf("%d%d",&v1,&v2),REVERSE(v1,v2);
		else if(op=="MAKE-SAME")scanf("%d%d%d",&v1,&v2,&v3),MAKE_SAME(v1,v2,v3);
		else if(op=="GET-SUM")scanf("%d%d",&v1,&v2),GET_SUM(v1,v2);
		else if(op=="MAX-SUM")MAX_SUM(rt);
	}
	return 0;
}

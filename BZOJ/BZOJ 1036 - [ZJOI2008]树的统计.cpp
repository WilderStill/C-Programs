#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1
#define rson rt<<1|1
#define ll long long
#define M 11451411
using namespace std;
struct ntr_node{ll fa,dep,son,size,top,dfn;}ntr[M];//普普通通的一棵树，fa父节点，dep深度，son重儿子，size子树大小，top当前重链的头，dfn dfs序
struct str_node{ll val,max;}str[M*4];//普普通通的一棵线段树
struct edge{ll to,nxt;}e[M*2];//链式前向星
ll tim,n,m,w[M],v[M];//tim时间戳，w[]由dfs序定位到的值，v[]原值 
ll tot,hd[M];
void add(ll u,ll v)	//建边 
{
	e[++tot]={v,hd[u]};hd[u]=tot;
	e[++tot]={u,hd[v]};hd[v]=tot;
}
void dfs1(ll u,ll f)//第一遍dfs，目的是找到重儿子 
{
	ntr[u].fa=f,ntr[u].dep=ntr[f].dep+1,ntr[u].size=1;
	ll maxsize=-1;
	for(ll i=hd[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v==f)continue;
		dfs1(v,u);
		ntr[u].size+=ntr[v].size;
		if(ntr[v].size>maxsize)maxsize=ntr[v].size,ntr[u].son=v;
	}
}
void dfs2(ll u,ll t)//第二遍dfs，目的是求每个节点的dfs序，同时求top 
{
	ntr[u].dfn=++tim;
	ntr[u].top=t;
	w[tim]=v[u];
	if(!ntr[u].son)return;
	dfs2(ntr[u].son,t);//注意，再往下找重链的过程中，top是不变的
	for(ll i=hd[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v==ntr[u].fa||v==ntr[u].son)continue;
		dfs2(v,v);
	} 
}
void pushup(ll rt){str[rt].val=(str[lson].val+str[rson].val);str[rt].max=max(str[lson].max,str[rson].max);}
void build(ll rt,ll l,ll r)//建树 
{
	if(l==r){str[rt].val=str[rt].max=w[l];return ;}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}
void update(ll now,ll l,ll r,ll rt,ll v)//没区间修改 
{
	if (l==r){str[rt].val=str[rt].max=v;return;}
    if(now<=mid)update(now,l,mid,lson,v);
    else update(now,mid+1,r,rson,v);
    pushup(rt);
}
ll query1(ll nowl,ll nowr,ll l,ll r,ll rt)//区间查询 
{
	ll res=-M;
	if(nowl<=l&&nowr>=r)return str[rt].max;
	if(nowl<=mid)res=max(res,query1(nowl,nowr,l,mid,lson));
	if(nowr>mid)res=max(res,query1(nowl,nowr,mid+1,r,rson));
	pushup(rt);
	return res;
}
ll query2(ll nowl,ll nowr,ll l,ll r,ll rt)//区间查询 
{
	ll res=0;
	if(nowl<=l&&nowr>=r)return str[rt].val;
	if(nowl<=mid)res+=query2(nowl,nowr,l,mid,lson);
	if(nowr>mid)res+=query2(nowl,nowr,mid+1,r,rson);
	pushup(rt);
	return res;
}
void modify(ll x,ll v){update(ntr[x].dfn,1,n,1,v);}
ll qchain(ll x,ll y)//query-chain 树链查询，与树链修改大同小异 
{
	ll res=0;
	while(ntr[x].top!=ntr[y].top)
	{
		if(ntr[ntr[x].top].dep<ntr[ntr[y].top].dep)swap(x,y);
		res+=query2(ntr[ntr[x].top].dfn,ntr[x].dfn,1,n,1);
		x=ntr[ntr[x].top].fa;
	}
	if(ntr[x].dep>ntr[y].dep)swap(x,y);
	res+=query2(ntr[x].dfn,ntr[y].dfn,1,n,1);
	return res;
}
ll qmax(ll x,ll y)
{
	ll res=-M;
	while(ntr[x].top!=ntr[y].top)
	{
		if(ntr[ntr[x].top].dep<ntr[ntr[y].top].dep)swap(x,y);
		res=max(res,query1(ntr[ntr[x].top].dfn,ntr[x].dfn,1,n,1));
		x=ntr[ntr[x].top].fa;
	}
	if(ntr[x].dep>ntr[y].dep)swap(x,y);
	res=max(res,query1(ntr[x].dfn,ntr[y].dfn,1,n,1));
	return res;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1,x,y;i<=n-1;i++){scanf("%lld%lld",&x,&y);add(x,y);}
	for(ll i=1;i<=n;i++)scanf("%lld",&v[i]);
	dfs1(1,1);dfs2(1,1);
	build(1,1,n);
	scanf("%lld",&m);
	for(ll i=1,x,y,val;i<=m;i++)
	{
		string op;
		cin>>op;
		if(op=="CHANGE"){scanf("%lld%lld",&x,&val);modify(x,val);}
		else if(op=="QMAX"){scanf("%lld%lld",&x,&y);printf("%lld\n",qmax(x,y));}
		else if(op=="QSUM"){scanf("%lld%lld",&x,&y);printf("%lld\n",qchain(x,y));}
	}
	return 0; 
}

#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson (rt<<1) 
#define rson (rt<<1|1)
#define ll long long
#define M 11451411
using namespace std;
struct ntr_node{ll fa,dep,son,size,top,dfn;}ntr[M];//����ͨͨ��һ������fa���ڵ㣬dep��ȣ�son�ض��ӣ�size������С��top��ǰ������ͷ��dfn dfs��
struct str_node{ll val,tag;}str[M*4];//����ͨͨ��һ���߶���
struct edge{ll to,nxt;}e[M*2];//��ʽǰ����
ll tim,n,m,w[M],v[M];//timʱ�����w[]��dfs��λ����ֵ��v[]ԭֵ 
ll tot,hd[M];
void add(ll u,ll v)	//���� 
{
	e[++tot]={v,hd[u]};hd[u]=tot;
	e[++tot]={u,hd[v]};hd[v]=tot;
}
void dfs1(ll u,ll f)//��һ��dfs��Ŀ�����ҵ��ض��� 
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
void dfs2(ll u,ll t)//�ڶ���dfs��Ŀ������ÿ���ڵ��dfs��ͬʱ��top 
{
	ntr[u].dfn=++tim;
	ntr[u].top=t;
	w[tim]=v[u];
	if(!ntr[u].son)return;
	dfs2(ntr[u].son,t);//ע�⣬�������������Ĺ����У�top�ǲ����
	for(ll i=hd[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v==ntr[u].fa||v==ntr[u].son)continue;
		dfs2(v,v);
	} 
}
void pushup(ll rt){str[rt].val=(str[lson].val+str[rson].val);}
void build(ll rt,ll l,ll r)//���� 
{
	if(l==r){str[rt].val=w[l];return ;}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}
void pushdown(ll rt,ll l,ll r)//�´� 
{
	str[lson].tag=str[lson].tag+str[rt].tag;
	str[lson].val=str[lson].val+str[rt].tag*(mid-l+1);
	str[rson].tag=str[rson].tag+str[rt].tag;
	str[rson].val=str[rson].val+str[rt].tag*(r-mid);
	str[rt].tag=0;
}
void update(ll nowl,ll nowr,ll l,ll r,ll rt,ll v)//û�����޸� 
{
	if(nowl<=l&&r<=nowr)
	{
		str[rt].val=(str[rt].val+v*(r-l+1));
		str[rt].tag=(str[rt].tag+v);
		return;
	}
	pushdown(rt,l,r);
	if(nowl<=mid)update(nowl,nowr,l,mid,lson,v);
	if(nowr>mid)update(nowl,nowr,mid+1,r,rson,v);
	pushup(rt);
}
ll query(ll nowl,ll nowr,ll l,ll r,ll rt)//�����ѯ 
{
	ll res=0;
	if(nowl<=l&&nowr>=r)return str[rt].val;
	pushdown(rt,l,r);
	if(nowl<=mid)res+=query(nowl,nowr,l,mid,lson);
	if(nowr>mid)res+=query(nowl,nowr,mid+1,r,rson);
	return res;
}
void modify(ll x,ll v){update(ntr[x].dfn,ntr[x].dfn+ntr[x].size-1,1,n,1,v);}
ll ask(ll x){return query(ntr[x].dfn,ntr[x].dfn+ntr[x].size-1,1,n,1);}
void mchain(ll x,ll y,ll v)	//modify-chain �����޸� 
{													
	while(ntr[x].top!=ntr[y].top)//����һ���������Ĺ��� 
	{
		if(ntr[ntr[x].top].dep<ntr[ntr[y].top].dep)swap(x,y);		
		update(ntr[ntr[x].top].dfn,ntr[x].dfn,1,n,1,v);
		x=ntr[ntr[x].top].fa;
	}
	if(ntr[x].dep>ntr[y].dep)swap(x,y);//��updateʱ����һ������С���ڶ�������������Ҫ��֤��һ������������ 
	update(ntr[x].dfn,ntr[y].dfn,1,n,1,v);
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1,x,y;i<=n-1;i++){scanf("%lld%lld",&x,&y);add(x+1,y+1);}
	scanf("%lld",&m);
	dfs1(1,1);dfs2(1,1);
	build(1,1,n);
	for(ll i=1,x,y,v;i<=m;i++)
	{
		char op;
		cin>>op;
		switch(op)
		{
			case 'A':{scanf("%lld%lld%lld",&x,&y,&v);mchain(x+1,y+1,v);break;}
			case 'Q':{scanf("%lld",&x);printf("%lld\n",ask(x+1));break;}
			default:break;
		}
	}
	return 0; 
}

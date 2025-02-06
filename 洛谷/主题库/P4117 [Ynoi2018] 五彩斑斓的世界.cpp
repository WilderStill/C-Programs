#include<bits/stdc++.h>
using namespace std;
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
inline void write(int x)
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
const int M=1000100,sqrtM=1010;
int blen,tot,maxn,mk,L[sqrtM],R[sqrtM],fa[M],rt[M],dg[M],num[M],blo[M],ans[M],cnt[M];
struct node{int op,l,r,x;}q[M];
inline int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
inline void merge(int x,int y)
{
	if(rt[y])fa[rt[x]]=rt[y];
	else rt[y]=rt[x],dg[rt[y]]=y;
	cnt[y]+=cnt[x];
	rt[x]=0;
	cnt[x]=0;
	return;
}
inline void init()
{
	memset(rt,0,sizeof rt);
	memset(cnt,0,sizeof cnt);
	return;
}
inline void build(int l,int r)
{
	maxn=0;mk=0;
	for(int i=l;i<=r;++i)
	{
		maxn=max(maxn,num[i]);
		if(rt[num[i]])fa[i]=rt[num[i]];
		else
		{
			fa[i]=i;
			rt[num[i]]=i;
			dg[i]=num[i];
		}
		++cnt[num[i]];
	}
	return;
}
inline void modify(int pl,int pr,int x)
{
	if((x<<1)<=maxn-mk)
	{
		for(int i=mk+1;i<=mk+x;++i)
		{
			if(!rt[i])continue;
			merge(i,i+x);
		}	
		mk+=x;
	}
	else
	{
		for(int i=maxn;i>mk+x;--i) 
		{
			if(!rt[i])continue;
			merge(i,i-x);
		}
		if(mk+x<maxn)maxn=mk+x;
	}
	return;
}
inline void restruct(int l,int r,int pl,int pr,int x)
{
	for(int i=l;i<=r;++i)
	{
		num[i]=dg[findfa(i)];
		rt[num[i]]=0;
		cnt[num[i]]=0;
		num[i]-=mk;
	}
	for(int i=l;i<=r;++i)dg[i]=0;
	for(int i=max(pl,l);i<=min(pr,r);++i)
		num[i]=num[i]>x?num[i]-x:num[i];
	return;
}
inline int query(int l,int r,int pl,int pr,int x)
{
	if(pl<=l&&r<=pr)return cnt[x+mk];
	else
	{
		int res=0;
		for(int i=max(l,pl);i<=min(r,pr);++i)
			if(dg[findfa(i)]==mk+x)++res;
		return res;
	}
}
int main()
{
	int n=read(),m=read();
	blen=sqrt(n);
	tot=(n-1)/blen+1;
	for(int i=1;i<=n;++i)
	{
		num[i]=read();
		blo[i]=(i-1)/blen+1;
		L[blo[i]]=(blo[i]-1)*blen+1;
		R[blo[i]]=min(blo[i]*blen,n);
	}
	for(int i=1;i<=m;++i)q[i]={read(),read(),read(),read()};
	for(int id=1;id<=tot;++id)
	{
		int l=L[id],r=R[id];
		init();
		build(l,r);
		for(int i=1;i<=m;++i)
		{
			int pl=q[i].l,pr=q[i].r,x=q[i].x;
			if(r<pl||pr<l)continue;
			if(q[i].op==1)
			{
				if(pl<=l&&r<=pr)modify(pl,pr,x);
				else
				{
					restruct(l,r,pl,pr,x);
					build(l,r);
				}
			}
			if(q[i].op==2)ans[i]+=query(l,r,pl,pr,x);
		}
	}
	for(int i=1;i<=m;++i)
		if(q[i].op==2)
			write(ans[i]),puts("");
	return 0;
}

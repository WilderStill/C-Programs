#include <bits/stdc++.h>
#define MAXN 1145141
#define ll long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int n,lim,q;
int dat[MAXN<<2],tg[MAXN<<2];
void pushup(int p)
{
	dat[p]=max(dat[p<<1],dat[p<<1|1]);
}
void pushdown(int p,int l,int r)
{
	if(tg[p])
	{
		dat[p<<1]+=tg[p];
		dat[p<<1|1]+=tg[p];
		tg[p<<1]+=tg[p];
		tg[p<<1|1]+=tg[p];
		tg[p]=0;
	}
}
void update(int l,int r,int rt,int lpos,int rpos,int k)
{
	if(l>rpos||r<lpos)
		return;
	if(l>=lpos&&r<=rpos)
	{
		dat[rt]+=k;
		tg[rt]+=k;
		return;
	} 
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	update(lson,lpos,rpos,k);
	update(rson,lpos,rpos,k);
	pushup(rt); 
} 
int main()
{
	scanf("%d%d%d",&n,&lim,&q);
	int l,r,x;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		update(1,n,1,l,r-1,x);
		if(dat[1]>lim)
		{
			update(1,n,1,l,r-1,-x);
			printf("N\n");
		}
		else printf("T\n");
	}
}

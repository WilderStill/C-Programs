#include<bits/stdc++.h>
#define M 1145141
using namespace std;
int n,m,ans,l=1,r,block,k;
int raw[M],num[M],vis[M],cnt[M],blo[M];
struct node
{
	int l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return x.l<y.l;
	if(!(blo[x.l]%2))return x.r>y.r;
	return x.r<y.r;
}
void add(int x)
{
	vis[++cnt[num[x]]]++;
	ans=max(ans,cnt[num[x]]);
}
void remove(int x)
{
	if(vis[cnt[num[x]]]==1&&cnt[num[x]]==ans)--ans;
    vis[cnt[num[x]]--]--;
}
int main()
{
	scanf("%d%d",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)scanf("%d",&raw[i]),num[i]=raw[i];
	sort(raw+1,raw+n+1);
	for(int i=1;i<=n;i++)num[i]=lower_bound(raw+1,raw+n+1,num[i])-raw-1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)remove(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)remove(r--);
		q[i].res=ans;
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%d\n",q[i].res);
	return 0;
}

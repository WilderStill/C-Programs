#include<bits/stdc++.h>
#define int long long
#define M 1145141
using namespace std;
int n,m,ans,l=1,r,block,k;
int num[M],vis[M],blo[M];
struct node{
	int l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return x.l<y.l;
	if(!(blo[x.l]%2))return x.r>y.r;
	return x.r<y.r;
}
void add(int x){ans+=vis[num[x]^k];vis[num[x]]++;}
void remove(int x){vis[num[x]]--;ans-=vis[num[x]^k];}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	block=n/sqrt(m);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]),num[i]^=num[i-1];
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].l--;
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
	for(int i=1,t1,t2;i<=m;i++)
	{
		printf("%lld\n",q[i].res);
	}
	return 0;
}

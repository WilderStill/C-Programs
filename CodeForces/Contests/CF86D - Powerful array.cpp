#include<bits/stdc++.h>
#define int long long
#define M 1145141
using namespace std;
int n,m,k,ans,l=1,r,block;
int num[M],vis[M],blo[M];
struct node{
	int l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if((x.l-1)/block==(y.l-1)/block) return x.r<y.r;
	return x.l/block<y.l/block;
}
void add(int x){ans+=(vis[num[x]]*2+1)*num[x];vis[num[x]]++;}//¼ÓÈë²Ù×÷
void remove(int x){ans-=(vis[num[x]]*2-1)*num[x];vis[num[x]]--;}//É¾³ı²Ù×÷
signed main()
{
	scanf("%lld%lld",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)add(--l);//×óÖ¸ÕëÍù×óÒÆ¼ÓÈë
		while(r<q[i].r)add(++r);//ÓÒÖ¸ÕëÍùÓÒÒÆ¼ÓÈë
		while(l<q[i].l)remove(l++);//×óÖ¸ÕëÍùÓÒÒÆÉ¾³ı
		while(r>q[i].r)remove(r--);//ÓÒÖ¸ÕëÍù×óÒÆÉ¾³ı
		q[i].res=ans;
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%lld\n",q[i].res);
	return 0;
}

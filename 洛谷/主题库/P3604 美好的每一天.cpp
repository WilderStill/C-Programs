#include<bits/stdc++.h>
#define M 1145141
using namespace std;
int n,m,ans,l=1,r,block,num[M],blo[M],cnt[(1<<26)+10];
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
inline void add(int x)
{
	ans+=cnt[num[x]];
	cnt[num[x]]++;
	for(int i=0;i<26;i++)ans+=cnt[num[x]^(1<<i)];
}
inline void remove(int x)
{
	cnt[num[x]]--;
	ans-=cnt[num[x]];
	for(int i=0;i<26;i++)ans-=cnt[num[x]^(1<<i)];
	return ;
}
int main()
{
	scanf("%d%d",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		num[i]=1<<(ch-'a');
		num[i]^=num[i-1];
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].l--;
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp2);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)remove(l++);
		while(l>q[i].l)add(--l);
		while(r>q[i].r)remove(r--);
		while(r<q[i].r)add(++r);
		q[i].res=ans;
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%d\n",q[i].res);
	return 0;
}

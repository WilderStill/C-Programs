#include<bits/stdc++.h>
#define M 1145141
using namespace std;
int n,m,l=1,r,block;
int num[M],vis[M],cnt[M],tot[M],blo[M];
struct node{
	int l,r,a,b,id,res1,res2;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return x.l<y.l;
	if(!(blo[x.l]%2))return x.r>y.r;//奇偶优化:多加了行判断
	return x.r<y.r;
}
void add(int x)//加入操作
{
    tot[num[x]]++;
	vis[blo[num[x]]]++;
    if(tot[num[x]]==1)cnt[blo[num[x]]]++;
}
void remove(int x)//删除操作
{
    tot[num[x]]--;
	vis[blo[num[x]]]--;
    if(tot[num[x]]==0)cnt[blo[num[x]]]--;
}
void getans(int a,int b,int &ans1,int &ans2)//分块找答案 
{
    for(int i=a;i<=min(b,blo[a]*block);i++)
        if(tot[i])ans1+=tot[i],ans2++;
    if(blo[a]!=blo[b])
        for(int i=(blo[b]-1)*block+1;i<=b;i++)
            if(tot[i])ans1+=tot[i],ans2++;
    for(int i=blo[a]+1;i<=blo[b]-1;i++)
        ans1+=vis[i],ans2+=cnt[i];
}
int main()
{
	scanf("%d%d",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].a,&q[i].b);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)add(--l);//左指针往左移加入
		while(l<q[i].l)remove(l++);//左指针往右移删除
		while(r<q[i].r)add(++r);//右指针往右移加入
		while(r>q[i].r)remove(r--);//右指针往左移删除
		getans(q[i].a,q[i].b,q[i].res1,q[i].res2);
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%d\n",q[i].res2);
	return 0;
}

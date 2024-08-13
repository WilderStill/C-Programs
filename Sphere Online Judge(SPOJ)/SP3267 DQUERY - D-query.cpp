#include<bits/stdc++.h>
#define M 1145141
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,m,ans,l=1,r,block;
int num[M],vis[M],blo[M];
struct node{
	int l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return x.l<y.l;
	if(!(blo[x.l]%2))return x.r>y.r;//奇偶优化:多加了行判断
	return x.r<y.r;
}
void add(int x){if(!vis[num[x]])ans++;vis[num[x]]++;}//加入操作
void remove(int x){vis[num[x]]--;if(!vis[num[x]])ans--;}//删除操作
int main()
{
	n=read();
	block=sqrt(n);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)num[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		q[i].l=read(),q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)add(--l);//左指针往左移加入
		while(l<q[i].l)remove(l++);//左指针往右移删除
		while(r<q[i].r)add(++r);//右指针往右移加入
		while(r>q[i].r)remove(r--);//右指针往左移删除
		q[i].res=ans;
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%d\n",q[i].res);
	return 0;
}

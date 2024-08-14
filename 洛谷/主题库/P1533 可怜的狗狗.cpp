#include <bits/stdc++.h>
#define M 414514
#define mid ((l+r)/2)
using namespace std;
int n,q,m,tot;
int a[M],b[M],t[M];	//a为原数组，b为辅助数组，t为根数组 
int sum[M<<5],lc[M<<5],rc[M<<5];//sum为结点，lc左儿子，rc右儿子，因为是可持久化结构，所以要开32倍 
int build(int l,int r)//建树，预先开点，作为初始版本 
{
	int rt=++tot;//1号根 
	sum[rt]=0;
	if(l<r)
	{
		lc[rt]=build(l,mid);
		rc[rt]=build(mid+1,r);
	}
	return rt;
}
int update(int pre,int l,int r,int x)//读取数组，加入新的数 
{
	int rt=++tot;//为它建一棵新树 
	lc[rt]=lc[pre];rc[rt]=rc[pre];sum[rt]=sum[pre]+1;//先复制，因为加入了一个点所以sum++ 
	if(l<r)
	{
		if(x<=mid)lc[rt]=update(lc[pre],l,mid,x);//递归查找需要更新的链 
		else rc[rt]=update(rc[pre],mid+1,r,x);
	}
	return rt;
}
int query(int st,int en,int l,int r,int k)		//关键操作：查询 
{												//原理是把每个版本的树都当成是一个前缀和 
	if(l==r) return l;							//两树相减就能得到中间的区间 
	int x=sum[lc[en]]-sum[lc[st]];				//反映到代码中，就是先查询，再作差 
	if(x>=k)return query(lc[st],lc[en],l,mid,k);//x为两树之差的左子树(小的部分)大小，如果超过k，就在左子树中找 
	else return query(rc[st],rc[en],mid+1,r,k-x);//否则，x比k小，还需要在右子树找(k-x)名的数 
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-(b+1);//离散化 
	t[0]=build(1,m);
	for(int i=1;i<=n;i++)
	{
		int rk=lower_bound(b+1,b+1+m,a[i])-b;//将树中的结点值从原数变为排名		
		t[i]=update(t[i-1],1,m,rk);
	}
	for(int i=1,x,y,z;i<=q;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		int rk=query(t[x-1],t[y],1,m,z);
		printf("%d\n",b[rk]);
	}
	return 0;
}

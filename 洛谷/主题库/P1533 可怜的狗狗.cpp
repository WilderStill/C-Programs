#include <bits/stdc++.h>
#define M 414514
#define mid ((l+r)/2)
using namespace std;
int n,q,m,tot;
int a[M],b[M],t[M];	//aΪԭ���飬bΪ�������飬tΪ������ 
int sum[M<<5],lc[M<<5],rc[M<<5];//sumΪ��㣬lc����ӣ�rc�Ҷ��ӣ���Ϊ�ǿɳ־û��ṹ������Ҫ��32�� 
int build(int l,int r)//������Ԥ�ȿ��㣬��Ϊ��ʼ�汾 
{
	int rt=++tot;//1�Ÿ� 
	sum[rt]=0;
	if(l<r)
	{
		lc[rt]=build(l,mid);
		rc[rt]=build(mid+1,r);
	}
	return rt;
}
int update(int pre,int l,int r,int x)//��ȡ���飬�����µ��� 
{
	int rt=++tot;//Ϊ����һ������ 
	lc[rt]=lc[pre];rc[rt]=rc[pre];sum[rt]=sum[pre]+1;//�ȸ��ƣ���Ϊ������һ��������sum++ 
	if(l<r)
	{
		if(x<=mid)lc[rt]=update(lc[pre],l,mid,x);//�ݹ������Ҫ���µ��� 
		else rc[rt]=update(rc[pre],mid+1,r,x);
	}
	return rt;
}
int query(int st,int en,int l,int r,int k)		//�ؼ���������ѯ 
{												//ԭ���ǰ�ÿ���汾������������һ��ǰ׺�� 
	if(l==r) return l;							//����������ܵõ��м������ 
	int x=sum[lc[en]]-sum[lc[st]];				//��ӳ�������У������Ȳ�ѯ�������� 
	if(x>=k)return query(lc[st],lc[en],l,mid,k);//xΪ����֮���������(С�Ĳ���)��С���������k���������������� 
	else return query(rc[st],rc[en],mid+1,r,k-x);//����x��kС������Ҫ����������(k-x)������ 
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-(b+1);//��ɢ�� 
	t[0]=build(1,m);
	for(int i=1;i<=n;i++)
	{
		int rk=lower_bound(b+1,b+1+m,a[i])-b;//�����еĽ��ֵ��ԭ����Ϊ����		
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

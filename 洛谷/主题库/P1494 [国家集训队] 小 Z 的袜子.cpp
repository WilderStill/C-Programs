#include<bits/stdc++.h>
#define int long long
#define M 1145141
using namespace std;
int n,m,ans,l=1,r,block;
int num[M],vis[M],blo[M];
int gcd(int x,int y)
{
    return (!y)?x:gcd(y,x%y);
}
struct node{
	int l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return x.l<y.l;
	if(!(blo[x.l]%2))return x.r>y.r;//��ż�Ż�:��������ж�
	return x.r<y.r;
}
void add(int x){ans+=vis[num[x]];vis[num[x]]++;}//�������
void remove(int x){vis[num[x]]--;ans-=vis[num[x]];}//ɾ������
signed main()
{
	scanf("%lld%lld",&n,&m);
	block=n/sqrt(m);//СС�Ż� 
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
		while(l>q[i].l)add(--l);//��ָ�������Ƽ���
		while(l<q[i].l)remove(l++);//��ָ��������ɾ��
		while(r<q[i].r)add(++r);//��ָ�������Ƽ���
		while(r>q[i].r)remove(r--);//��ָ��������ɾ��
		q[i].res=ans;
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1,t1,t2;i<=m;i++)
	{
		if(q[i].l==q[i].r)printf("0/1\n");
		else
		{
			t1=(q[i].r-q[i].l+1)*(q[i].r-q[i].l)/2;
			t2=gcd(q[i].res,t1);
			printf("%lld/%lld\n",q[i].res/t2,t1/t2);
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
int n,m,buc[11451411],buc2[11451411],del1[11451411],del2[11451411],tr1[11451411],tr2[11451411],num;
void add1(int x,int v)
{
	if(x==0)return;
	for(int i=x;i<=n+m;i+=lowbit(i))tr1[i]+=v;
}
int query1(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))ans+=tr1[i];
	return ans;
}
void add2(int x,int v)
{
	if(x==0)return;
	for(int i=x;i<=n+m;i+=lowbit(i))tr2[i]+=v;
}
int query2(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))ans+=tr2[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	num=n;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		buc[x]++;
	}
	for(int i=1;i<=n+m;++i)buc2[buc[i]]++;
	del1[0]=buc2[0];
	for(int i=1;i<=n+m;++i)del1[i]=del1[i-1]+buc2[i];
	for(int i=1;i<=n+m;++i)del2[i]=del2[i-1]+buc2[i]*i;
	for(int i=1;i<=n+m;++i)tr1[i]=del1[i]-del1[i-lowbit(i)];
	for(int i=1;i<=n+m;++i)tr2[i]=del2[i]-del2[i-lowbit(i)];
	for(int i=1,op,x;i<=m;++i)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			buc[x]++;num++;
			buc2[buc[x]-1]--;buc2[buc[x]]++;
			add1(buc[x]-1,-1);add1(buc[x],1);
			add2(buc[x]-1,-(buc[x]-1));add2(buc[x],buc[x]);
		}
		else if(op==2)
		{
			buc[x]--;num--;
			buc2[buc[x]+1]--;buc2[buc[x]]++;
			add1(buc[x]+1,-1);add1(buc[x],1);
			add2(buc[x]+1,-(buc[x]+1));add2(buc[x],buc[x]);
		}
		else
		{
			int ans=num-query2(x)-(query1(num)-query1(x))*x;
			ans=max(ans,0);
			printf("%d\n",ans);
		}
	}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c,d;
}dot[50004];
int n,ans,f[50004];
bool cmp(node x,node y)
{
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	if(x.c!=y.c)return x.c<y.c;
	return x.d<y.d;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&dot[i].a,&dot[i].b,&dot[i].c,&dot[i].d);
	sort(dot+1,dot+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=max(0,i-7500);j<i;j++)
			if((dot[j].b<=dot[i].b)&(dot[j].c<=dot[i].c)&(dot[j].d<=dot[i].d)&(f[j]>f[i]))
				f[i]=f[j];
		f[i]++;
	}
	for(int i=1;i<=n;i++)ans=ans>f[i]?ans:f[i];
	printf("%d",ans);
	return 0;
}

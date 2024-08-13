#include<bits/stdc++.h>
#define M 414514
using namespace std;
int n,m,s[M],t[M],dels[M],delt[M],nxt[M],ans;
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1) 
	{
		printf("%d",n);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&s[i]);
		if(n!=1)dels[i-1]=s[i]-s[i-1];
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&t[i]);
		if(m!=1)delt[i-1]=t[i]-t[i-1];
	}
	delt[m]=-M;
	for(int i=m+1;i<=m+n-1;++i)delt[i]=dels[i-m];
	for(int cur=2,now=0;cur<=n+m-1;++cur)
	{
		while(now>0&&delt[now+1]!=delt[cur])now=nxt[now];
		if(delt[now+1]==delt[cur])++now;
		nxt[cur]=now;
		if(now==m-1)++ans;
	}
	printf("%d",ans);
	return 0;
}

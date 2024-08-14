#include<bits/stdc++.h>
#define M 411451
#define ll long long
using namespace std;
ll t,n,m,cnt,hd[M],fk[M],sum,beg,endg;
bool vis[M];
ll find(ll x){return (fk[x]==x)?x:(fk[x]=find(fk[x]));}
void unity(ll x,ll y){fk[find(x)]=find(y);}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		memset(hd,0,sizeof hd);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)fk[i]=i;
		cnt=sum=beg=0;
		for(int i=1,u,v;i<=m;i++)
		{
			scanf("%lld %lld",&u,&v);
			unity(u,v);
		}
		for(int i=1;i<=n;i++)
		{
			ll tmp=find(i);
			if(!beg)beg=tmp;
			if(tmp!=beg)endg=tmp;
			if(!vis[tmp])
			{
				sum++;
				vis[tmp]=1;
			}
		}
		if(sum==1)
		{
			printf("No\n");continue;
		}
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			if(fk[i]!=beg)
			{
				if(fk[i]==endg&&fk[i]==i)continue;
				printf("%lld %lld\n",i,beg);
			}
			else printf("%lld %lld\n",i,endg);
		}
	}
	return 0;
}

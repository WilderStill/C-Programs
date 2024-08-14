#include<bits/stdc++.h>
#define M 1145141
using namespace std;
const int mod=998244353;
int n,m,q,buc[M],k[M],power[M],sth[M],idx[M];
int main()
{
	scanf("%d%d",&n,&q);
	power[0]=1;
	memset(sth,-1,sizeof sth);
	for(int i=0,w;i<n;++i)scanf("%d",&w),buc[w]++;
	for(int i=0;i<M;++i)
	{
		if(i)power[i]=((power[i-1])<<1)%mod;
		if(buc[i]>2) 
		{
			if(buc[i]&1)buc[i+1]+=((buc[i]-1)>>1),buc[i]=1; 
			else buc[i+1]+=((buc[i]-1)>>1),buc[i]=2;
		}
	}
	int x=-1;
	for(int i=0;i<M;++i)
	{
		idx[i]=x;
		if(buc[i]==2)x=i;
		if(!buc[i])x=-1;
	}
	for(int i=M-1;i;--i)
	{
		if(buc[i]==2)sth[i]=i+1;
		if(buc[i])sth[i-1]=i;
		else sth[i-1]=sth[i];
	}
	for(int i=1,t,ans,x,tmp;i<=q;++i)
	{
		t=M,ans=0,x=-1,tmp=-1;
		scanf("%d",&m);
		for(int j=0;j<m;j++)scanf("%d",&k[j]);
		for(int j=0;j<m;j++)
		{
			if(sth[k[j]]<t&&~sth[k[j]])tmp=ans+power[sth[k[j]]];
			if(!buc[k[j]]||k[j]>=t)
			{
				if(k[j]>t){ans=-1;goto pt;}
				else
				{
					if(!(~idx[k[j]])){ans=-1;goto pt;}
					else if(~x&&idx[k[j]]>x)t=x;
					else t=idx[k[j]];
				}
			}
			else if(buc[k[j]]==1)t=k[j];
			else x=idx[k[j]];
			ans+=power[k[j]];
			ans%=mod;
		}
pt:		if(!(~ans)&&~tmp)ans=tmp%mod;
		printf("%d\n",ans);
	}
	return 0;
}

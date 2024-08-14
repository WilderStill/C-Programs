#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 200010
using namespace std;
int T,n,a[M],pre[M],suf[M],pos[M];
int main()
{
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		scanf("%d",&n);
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		memset(pos,INF,sizeof pos);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),pre[i]=suf[i]=1;
		for(int i=n;i;--i)
			if(a[i]<a[i+1])
				pre[i]=pre[i+1]+1;
		for(int i=1;i<=n;++i)
			if(a[i-1]<a[i])
				suf[i]=suf[i-1]+1;
		pos[1]=a[1];
		for(int i=1;i<=n;++i)
		{
			int tp=lower_bound(pos+1,pos+n+1,a[i])-pos-1;
			ans=max(ans,tp+pre[i]); 
			pos[suf[i]]=min(a[i],pos[suf[i]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

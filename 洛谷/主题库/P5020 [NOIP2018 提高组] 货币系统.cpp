#include<bits/stdc++.h>
#define ll int
#define M 25001
using namespace std;
ll T,n,num[M],f[M],maxn=0,ans;
signed main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		ans=0;
		scanf("%d",&n);
		for(ll i=1;i<=n;++i)scanf("%d",&num[i]),maxn=max(maxn,num[i]);
		sort(num+1,num+n+1);
		for(ll i=1;i<=n;++i)
		{
			if(!f[num[i]])++ans;
			f[num[i]]=1;
			for(ll j=1;j<=M-num[i];++j)
				if(f[j])
					f[num[i]+j]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

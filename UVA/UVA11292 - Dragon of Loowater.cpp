#include<bits/stdc++.h>
using namespace std;
int hd[20010],ht[20010];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		for(int i=1;i<=n;++i)scanf("%d",&hd[i]);
		for(int i=1;i<=m;++i)scanf("%d",&ht[i]);
		sort(hd+1,hd+n+1),sort(ht+1,ht+m+1);
		int cnt=1,ans=0;
		for(int i=1;i<=m;++i)
			if(ht[i]>=hd[cnt])
			{
				ans+=ht[i];
				if(++cnt>n)break;
			}
		if(cnt<=n)puts("Loowater is doomed!");
		else printf("%d\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
#define M 114514
using namespace std;
int T,n,ans,x[M],y[M];
char str[M];
int main()
{
	scanf("%d",&T);
	getchar();getchar();
	while(T--)
	{
		ans=n=0;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		while(gets(str))
		{
			if(!str[0]&&n)break;
			sscanf(str,"%d %d",&x[n],&y[n]);
			++n;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				int maxn=2;
				for(int k=0;k<n;++k)
				{
					if(k==i||k==j)continue;
					if((x[k]-x[i])*(y[k]-y[j])==(y[k]-y[i])*(x[k]-x[j]))maxn++;
				}
				ans=max(maxn,ans);
			}
		}
		printf("%d\n",ans);
        if(T)puts("");
	}
	return 0;
}

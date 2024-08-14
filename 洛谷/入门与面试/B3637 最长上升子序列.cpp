#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,lis[M],f[M],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&lis[i]);
	memset(f,0x3f3f3f3f,sizeof(f));
	f[1]=lis[1];
	for(int i=1;i<=n;i++)
	{
		int t=lower_bound(f+1,f+i+1,lis[i])-f;
		ans=max(ans,t);
		f[t]=lis[i];
	}
	printf("%d",ans);
	return 0;
}

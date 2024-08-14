#include<bits/stdc++.h>
using namespace std;
int TJ[54010],QW[54010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&TJ[i]);
	for(int i=1;i<=n;++i)scanf("%d",&QW[i]);
	sort(TJ+1,TJ+n+1);
	sort(QW+1,QW+n+1);
	int ans=0,slow_QW=1;
	for(int i=1;i<=n;++i)
	{
		if(TJ[i]>=QW[slow_QW])
		{
			++ans;++slow_QW;
		}
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int TJ[2010],QW[2010];
void solve(int n)
{
	for(int i=1;i<=n;++i)scanf("%d",&TJ[i]);
	for(int i=1;i<=n;++i)scanf("%d",&QW[i]);
	sort(TJ+1,TJ+n+1);
	sort(QW+1,QW+n+1);
	int ans=0,slow_TJ=1,slow_QW=1,fast_TJ=n,fast_QW=n;
	for(int i=1;i<=n;++i)
	{
		if(TJ[fast_TJ]>QW[fast_QW])
		{
			ans+=200;
			--fast_TJ;
			--fast_QW;
		}
		else if(TJ[fast_TJ]<QW[fast_QW])
		{
			ans-=200;
			++slow_TJ;
			--fast_QW;
		}
		else if(TJ[slow_TJ]>QW[slow_QW])
		{
			ans+=200;
			++slow_TJ;
			++slow_QW;
		}
		else
		{
			if(TJ[slow_TJ]<QW[fast_QW])ans-=200;
			++slow_TJ;
			--fast_QW;
		}
	}
	printf("%d",ans);
	return;
} 
int main()
{
	int n;
	scanf("%d",&n);
	solve(n);
	return 0;
}

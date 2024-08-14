#include<bits/stdc++.h>
using namespace std;
int n,d,cases;
double ans;
int main()
{
	while(~scanf("%d%d",&n,&d))
	{
		if(!n&&!d)return 0;
		ans=1.0*d;
		for(int i=1,p,l,v;i<=n;i++)
		{
			scanf("%d%d%d",&p,&l,&v);
			ans=ans-l+2.0*l/v;
		}
		printf("Case %d: %.3lf\n\n",++cases,ans);
	}
}

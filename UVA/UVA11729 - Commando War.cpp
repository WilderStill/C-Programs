#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,t;
	bool operator <(node b){return t^b.t?t>b.t:x<b.x;}
}tp[100010];
int main()
{
	int n,cases=0;
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;++i)scanf("%d%d",&tp[i].x,&tp[i].t);
		sort(tp+1,tp+n+1);
		int tm=0,ans=0;
		for(int i=1;i<=n;++i)tm+=tp[i].x,ans=max(tm+tp[i].t,ans);
		printf("Case %d: %d\n",++cases,ans);
	}
	return 0;
}

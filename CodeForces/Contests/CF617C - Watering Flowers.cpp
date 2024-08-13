#include<bits/stdc++.h>
#define int long long 
using namespace std;
int dist(int x1,int y1,int x2,int y2){return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}
struct node
{
	int d1,d2;
}dd[100010];
bool cmp(const node&a,const node&b)
{
	if(a.d1^b.d1)return a.d1<b.d1;
	return a.d2<b.d2;
}
signed main()
{
	int x1,y1,x2,y2,n;
	scanf("%lld%lld%lld%lld%lld",&n,&x1,&y1,&x2,&y2);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%lld%lld",&x,&y);
		dd[i].d1=dist(x1,y1,x,y);
		dd[i].d2=dist(x2,y2,x,y);
	}
	sort(dd+1,dd+n+1,cmp);
	int ans=dd[n].d1,h=0;
	for(int i=n;i;--i)
	{
		h=max(h,dd[i].d2);
		ans=min(ans,h+dd[i-1].d1);
	}
	printf("%lld",ans);
}

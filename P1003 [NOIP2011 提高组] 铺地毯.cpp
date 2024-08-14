#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans;
struct sb
{
	int a,b,c,d;
}v[11451411];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&v[i].a,&v[i].b,&v[i].c,&v[i].d);
	scanf("%d %d",&x,&y);
	for(int i=1;i<=n;i++)
	{
		if(x>=v[i].a&&x<=v[i].a+v[i].c&&y>=v[i].b&&y<=v[i].b+v[i].d)ans=i;
	}
	if(ans==0)printf("-1");
	else printf("%d",ans);
	return 0;
}

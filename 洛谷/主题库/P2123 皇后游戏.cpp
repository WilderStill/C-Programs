#include<bits/stdc++.h>
#define ll long long
#define M 11451411
using namespace std;
struct nd
{
    int x,y,d;
}peo[M];
bool cmp(nd a,nd b)
{
	if(a.d!=b.d) return a.d<b.d;
    if(a.d<=0) return a.x<b.x;
    return a.y>b.y;
}
int t,n;
ll ans[M];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
		{
			scanf("%d%d",&peo[i].x,&peo[i].y);
			if(peo[i].x>peo[i].y)peo[i].d=1;
			else if(peo[i].x<peo[i].y) peo[i].d=-1;
			else peo[i].d=0;
		}
        sort(peo+1,peo+n+1,cmp);
        ll s=0;
        for(int i=1;i<=n;i++)
        {
            s+=peo[i].x;
            ans[i]=max(ans[i-1],s)+peo[i].y;
        }
        printf("%lld\n",ans[n]);
    }
}

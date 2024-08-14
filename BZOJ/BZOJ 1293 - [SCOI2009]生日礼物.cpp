#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,p;
}s[1000008];
int ans=0x3f3f3f3f,sum,n,cnt,hd=1,tl=0,vis[1000008];
bool cmp(node a,node b){return a.p<b.p;}
int main()
{
    memset(vis,-1,sizeof(vis));
	scanf("%d%d",&n,&sum);
    for(int i=1;i<=sum;++i)
	{
        int k;
    	scanf("%d",&k);
        for(int j=1;j<=k;++j)
        {
            scanf("%d",&s[++cnt].p);
            s[cnt].x=i;
        }
	}
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;++i)
	{
		if(vis[s[i].x]==-1)++tl;
		vis[s[i].x]=s[i].p;
		while(hd<=i&&s[hd].p!=vis[s[hd].x])++hd;
		if(tl==sum)ans=min(ans,s[i].p-s[hd].p);
	}
    printf("%d",ans);
    return 0;
}

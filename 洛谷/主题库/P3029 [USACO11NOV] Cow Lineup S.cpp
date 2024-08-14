#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,p;
}s[714514];
int ans=2e9,sum,n,hd,tl;
map<int,int>mp;map<int,bool>vis;
bool cmp(node a,node b){return a.x<b.x;}
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;++i)
	{
    	scanf("%d%d",&s[i].x,&s[i].p);
    	if(!vis[s[i].p])++sum,vis[s[i].p]=1;
	}
    sort(s+1,s+n+1,cmp);
    tl=hd=1;
    ++mp[s[1].p];
    for(int i=1;i<=n;++i)
	{
        while(hd<sum&&tl<n)
		{
			++tl;
            ++mp[s[tl].p];
            if(mp[s[tl].p]==1)++hd;
        }
        if(hd==sum)ans=min(ans,s[tl].x-s[i].x);
        mp[s[i].p]--;
        if(mp[s[i].p]==0)--hd;
    }
    printf("%d",ans);
    return 0;
}

// LUOGU_RID: 190205504
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int dfn[100010],low[100010],idx[100010],tim,tot=1;
vector<int>mp[100010],tr[100010];
inline void dfs(int pos,int fa)
{
    dfn[pos]=low[pos]=++tim;
    for(auto to:mp[pos])
    {
    	if(to==fa)continue;
    	if(dfn[to])low[pos]=min(low[pos],dfn[to]);
        else
		{
            dfs(to,pos);
            low[pos]=min(low[pos],low[to]);
        }
	}
}
inline void bfs(int pos)
{
	queue<int>q;
	idx[pos]=tot;
	q.push(pos);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto to:mp[top])
		{
			if(idx[to])continue;
			if(dfn[to]<low[top]||dfn[top]<low[to])
			{
				++tot;
				bfs(to);
				tr[idx[top]].push_back(idx[to]);
				tr[idx[to]].push_back(idx[top]);
			}
			else
			{
				idx[to]=idx[pos];
				q.push(to);
			}
		}
	}
}
int main()
{
	int n=read(),m=read(),ans=0x3f3f3f3f,cnt=0;
	bool fg=0;
	for(int i=1;i<=m;++i)
	{
		int u=read()+1,v=read()+1;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])dfs(i,0);
	for(int i=1;i<=n;++i)if(!idx[i])bfs(i);
	if(tot==1||n==3)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i=1;i<=tot;++i)
	{
		if(tr[i].size()>=2)continue;
		++cnt;
		if(fg)continue;
		for(auto to:tr[i])if(tr[to].size()>=3)fg=1;
	}
	if(tot<=3)ans=min(ans,tot-2);
	if(fg)ans=min(ans,cnt>>1);
	else ans=min(ans,cnt+1>>1);
	write(ans);
	puts("");
	return 0;
}

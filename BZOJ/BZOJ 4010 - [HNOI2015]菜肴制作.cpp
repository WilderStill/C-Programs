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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
priority_queue<int>hp;
int tot,hd[300010],indeg[300010],ans[300010];
struct edge
{
	int to,nxt;
}edge[300010];
void addedge(int u,int v)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	hd[u]=tot;
	indeg[v]++;
}
int main()
{
	int T=read();
	while(T--)
	{
		memset(hd,0,sizeof hd);
		memset(indeg,0,sizeof indeg);
		tot=0;
		int n=read(),m=read();
		bool fg=0;
		for(int i=1;i<=m;++i)
		{
	        int u=read(),v=read();
	        addedge(v,u);
			if(u==v)fg=1;
	    }
	    if(fg)
		{
			puts("Impossible!");
			continue;
		}
	    for(int i=1;i<=n;++i)if(!indeg[i])hp.push(i);
	    int len=0;
	    while(!hp.empty())
		{
	        int top=hp.top();hp.pop();
			ans[++len]=top;
	        for(int i=hd[top];i;i=edge[i].nxt)
	        {
	        	int v=edge[i].to;
	        	if(!(--indeg[v]))hp.push(v);
			}
	    }
	    if(len<n)
		{
			puts("Impossible!");
			continue;
		}
	    for(int i=n;i>=1;i--)printf("%d ",ans[i]);
	    puts("");
	}
	return 0;
}

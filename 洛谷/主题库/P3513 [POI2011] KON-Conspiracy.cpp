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
int dfn[100010],low[100010],scc[100010],hd[100010],stk[100010],top,tot,scccnt,tim;
int syh[100010],cnt_syh,dg[100010],cnt_dg,ct[100010],cp[100010],ans,cnt1,cnt2;
bool mp[5010][5010],inst[100010],vis[100010];
struct node
{
	int to,nxt;
}edge[25000010];
inline void addedge(int u,int v)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	hd[u]=tot;
}
inline void tarjan(int pos)
{
	dfn[pos]=low[pos]=++tim;
	stk[++top]=pos;
	inst[pos]=1;
	for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(!dfn[to])
		{
			tarjan(to);
			low[pos]=min(low[pos],low[to]);
		}
		else if(inst[to])low[pos]=min(low[pos],dfn[to]);
	}
	if(dfn[pos]==low[pos])
	{
		int tp;
		++scccnt;
		do
		{
			tp=stk[top--];
			inst[tp]=0;
			scc[tp]=scccnt;
		}while(tp!=pos);
	}
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		for(int j=1;j<=x;++j)mp[i][read()]=1;
		for(int j=1;j<=n;++j)
		{
			if(i==j)continue;
			mp[i][j]?addedge(i+n,j):addedge(i,j+n);
		}
	}
	for(int i=1;i<=2*n;++i)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;++i)
	{
		if(scc[i]==scc[i+n])
		{
			puts("0");
			return 0;
		}
		if(scc[i]<scc[i+n])
		{
			syh[++cnt_syh]=i;
			vis[i]=1;
		}
		else dg[++cnt_dg]=i;
	}
	if(cnt_syh&&cnt_dg)ans=1;
	for(int i=1;i<=cnt_syh;++i)
	{
		for(int j=1;j<=cnt_dg;++j)
		{
			if(mp[syh[i]][dg[j]])
			{
				++ct[syh[i]];
				cp[syh[i]]=dg[j];
			}
			else
			{
				++ct[dg[j]];
				cp[dg[j]]=syh[i];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(ct[i]==1&&!ct[cp[i]])++ans;
		else if(!ct[i])
		{
			if((vis[i]&&cnt_syh>1)||(!vis[i]&&cnt_dg>1))
			{
				++ans;
				vis[i]?++cnt1:++cnt2;
			}
		}
	}
	write(cnt1*cnt2+ans);
	return 0;
}

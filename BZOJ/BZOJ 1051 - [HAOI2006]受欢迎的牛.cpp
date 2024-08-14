#include<bits/stdc++.h>
#define M 514514
using namespace std;
int n,m,dfn[M],low[M],scc[M],scclen[M],buk[M],sccnum,tim,Noincnt,ans;
bool inst[M];
vector<int>edge[M];
stack<int>st;
void tarjan(int x)
{
    low[x]=dfn[x]=++tim;
    st.push(x);
    inst[x]=1;
    for(int i=0;i<edge[x].size();i++)
	{
        int v=edge[x][i];
        if(!dfn[v])
		{
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
		else if(inst[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
	{
        sccnum++;
        while(1)
		{
			int t=st.top();
            st.pop();
            scc[t]=sccnum;
            scclen[sccnum]++;
            inst[t]=0;
			if(t==x)break;
		}
    }
}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
        edge[x].push_back(y);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++)
        for(int j=0;j<edge[i].size();j++)
            if(scc[i]!=scc[edge[i][j]])buk[scc[i]]++;
    for(int i=1;i<=sccnum;i++)
        if(!buk[i])
		{
            if(Noincnt==1){ans=0;break;}
			Noincnt++;
            ans=scclen[i];
        }
    printf("%d",ans);
    return 0;
}

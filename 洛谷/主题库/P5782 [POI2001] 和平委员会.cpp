#include<bits/stdc++.h>
#define NDEBUG
#define M 114514
using namespace std;
int n,m,low[M],dfn[M],tim,sccnum,scc[M];
vector<int>edge[M];
stack<int> st;
bool inst[M];
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
		edge[x].push_back(y%2?y+1:y-1);
		edge[y].push_back(x%2?x+1:x-1);
	}
	for(int i=1;i<=2*n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=2*n;i+=2)
	{
		if(i%2==1&&scc[i]==scc[i+1])
		{
			puts("NIE");
			return 0;
		}
	}
	for(int i=1;i<=2*n;i+=2)
		printf("%d\n",(scc[i]<scc[i+1])?i:i+1);
	return 0;
}

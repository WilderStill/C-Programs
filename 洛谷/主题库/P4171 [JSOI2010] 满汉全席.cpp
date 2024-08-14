#include<bits/stdc++.h>
#define M 2145141
using namespace std;
int n,m,low[M],dfn[M],tim,sccnum,scc[M],t;
vector<int>edge[M];
stack<int>st;
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
	scanf("%d",&t);
	while(t--)
	{
		tim=sccnum=0;
		for(int i=1;i<=M;i++)edge[i].clear();
		while(!st.empty())st.pop();
		memset(dfn,0,sizeof dfn);
		memset(scc,0,sizeof scc);
		memset(low,0,sizeof low);
		memset(inst,0,sizeof inst);
		scanf("%d%d",&n,&m);
		for(int i=1,x,y,tmp;i<=m;i++)
		{
			char s1[114],s2[114];
			scanf("%s%s",&s1,&s2);
			x=y=0;
            tmp=1;while(isdigit(s1[tmp]))x=x*10+s1[tmp++]-'0';
            tmp=1;while(isdigit(s2[tmp]))y=y*10+s2[tmp++]-'0';
            if(s1[0]=='m')
            {
                if(s2[0]=='h')edge[x+n].push_back(y+n),edge[y].push_back(x);
                else edge[x+n].push_back(y),edge[y+n].push_back(x);
            }
            else
            {
                if(s2[0]=='m')edge[x].push_back(y),edge[y+n].push_back(x+n);
                else edge[x].push_back(y+n),edge[y].push_back(x+n);
            }
		}
		for(int i=1;i<=2*n;i++)if(!dfn[i])tarjan(i);
		bool isOut=0;
		for(int i=1;i<=n;i++)
			if(scc[i]==scc[i+n])
			{
				isOut=1;
				break;
			}
		if(!isOut)puts("GOOD");
		else puts("BAD");
	}
	return 0;
}

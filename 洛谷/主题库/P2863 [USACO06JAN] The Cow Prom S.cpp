#include<bits/stdc++.h>
#define M 1145141
using namespace std;
vector<int>mp[M];
stack<int>st;
int n,m,dfn[M],vis[M],low[M],SCC[M],num[M],SCCnum=0,tim=0,ans=0;
void tarjan(int x)
{
    dfn[x]=low[x]=++tim;
    st.push(x);
    vis[x]=1;
    for(int i=0;i<mp[x].size();i++)
        if(!dfn[mp[x][i]])
        {
            tarjan(mp[x][i]);
            low[x]=min(low[x],low[mp[x][i]]);
        }
        else if(vis[mp[x][i]])
			low[x]=min(low[x],dfn[mp[x][i]]);
    if(low[x]==dfn[x])
    {
        SCCnum++;
        while(st.top()!=x)
        {
            int tmp=st.top();
            st.pop();
		    SCC[tmp]=SCCnum;
		    num[SCCnum]++;
		    vis[tmp]=0;
        }
        st.pop();
		SCC[x]=SCCnum;
		num[SCCnum]++;
		vis[x]=0;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        mp[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
	    if(!dfn[i])tarjan(i);
    for(int i=1;i<=SCCnum;i++)
		if(num[i]>1)ans++;
    printf("%d",ans);
    return 0;
}

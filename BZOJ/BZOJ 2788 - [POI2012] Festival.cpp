#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 1145
using namespace std;
int mp[M][M];
stack<int>st;
int n,m1,m2,dfn[M],vis[M],low[M],SCC[M],tim,cnt,ans[M];
inline int read()
{
	register int x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
inline void tarjan(int x)
{
    dfn[x]=low[x]=++tim;
    st.push(x);
    vis[x]=1;
    for(register int i=1;i<=n;++i)
    	if(mp[x][i]<=1)
		{
			if(!dfn[i]){tarjan(i);low[x]=min(low[i],low[x]);}
			else if(vis[i])low[x]=min(low[x],dfn[i]); 
		}
    if(low[x]==dfn[x])
    {
    	register int tmp=st.top();
        while(tmp!=x)
        {
            st.pop();
		    SCC[tmp]=x;
		    vis[tmp]=0;
		    tmp=st.top();
        }
        st.pop();
		SCC[tmp]=x;
		vis[x]=0;
    }
    return;
}
int main()
{
	n=read(),m1=read(),m2=read();
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)     
            mp[i][j]=((i==j)?0:INF);
    for(register int i=1,x,y;i<=m1;++i)
    {
        x=read(),y=read();
        mp[x][y]=min(1,mp[x][y]);
        mp[y][x]=min(-1,mp[y][x]);
    }
    for(register int i=1,x,y;i<=m2;++i)
    {
        x=read(),y=read();
        mp[y][x]=min(0,mp[y][x]);
    }
    for(register int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
    for(register int k=1;k<=n;++k)
		for(register int i=1;i<=n;++i)
			if(SCC[i]==SCC[k]&&mp[i][k]!=INF)
				for(register int j=1;j<=n;++j)
					if(SCC[i]==SCC[j])
						mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
	for(register int i=1;i<=n;++i)
	{
		if(mp[i][i]<0){puts("NIE");exit(0);}
		for(register int j=1;j<=n;++j) 
			if(SCC[i]==SCC[j])
				ans[SCC[i]]=max(ans[SCC[i]],mp[i][j]+1);
	}
	cnt=0;
	for(register int i=1;i<=n;++i)cnt+=ans[i];
	printf("%d",cnt);
	return 0;
}

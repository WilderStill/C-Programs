#include<bits/stdc++.h>
using namespace std;
#define int long long
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
namespace Wilder_Graph
{
	const int M=1000010,INF=0x3f3f3f3f,jINF=1000000000;
	struct Graph
	{
		struct node
		{
		    int from,to,nxt,val;
		}edge[M<<1],tpedge[M<<1];
		int dotnum,tot,hd[M],ind[M],oud[M],fa[M],nval[M],floyd_mp[5010][5010],graph_dis[M];
		bool graph_vis[M];
		inline void addedge(int u,int v,int w)
		{
			edge[++tot].from=u;
			edge[tot].to=v;
			edge[tot].val=w;
			edge[tot].nxt=hd[u];
			hd[u]=tot;
			++oud[u],++ind[v];
		}
		inline void build(int n,int m,bool isDir,bool isVal)
		{
			tot=0,dotnum=n;
			memset(hd,0,sizeof hd);
			for(int i=1;i<=m;++i)
			{
				int u=read(),v=read(),w=isVal?read():0;
				if(u^v)
				{
					addedge(u,v,w);
					if(!isDir)addedge(v,u,w);
				}
			}
		}
		inline void build_floyd_mp(int n,int m,bool way)
		{
			dotnum=n;
			if(!way)
			{
				for(int i=1;i<=n;++i)
			        for(int j=1;j<=n;++j)
					{          
			            floyd_mp[i][j]=INF;
			            if(i==j)floyd_mp[i][j]=0;
			        }
				for(int i=1;i<=m;++i)
				{
					int u=read(),v=read(),w=read();
					floyd_mp[u][v]=floyd_mp[v][u]=min(floyd_mp[u][v],w);
				}
			}
			else
			{
				for(int i=1;i<=n;++i)
					for(int j=1;j<=n;++j)
						floyd_mp[i][j]=read();
			}
		}
		queue<int>topo_q;
		inline vector<int>topo()
		{
			vector<int>res;
			for(int i=1;i<=dotnum;++i)
				if(!ind[i])
				{
					res.push_back(i);
					topo_q.push(i);
				}
		    while(!topo_q.empty())
			{
		        int top=topo_q.front();
				topo_q.pop();
		        for(int i=hd[top];i;i=edge[i].nxt)
		        {
		        	--ind[edge[i].to];
		        	if(!(ind[edge[i].to]))
		        	{
		        		res.push_back(edge[i].to);
						topo_q.push(edge[i].to);
					}
				}
		    }
		    return res;
		}
		inline int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
		inline int Kruskal()
		{
			int res=0;
			for(int i=1;i<=dotnum;++i)fa[i]=i;
			sort(edge+1,edge+tot+1,[](node a,node b){return a.val<b.val;});
			for(int i=1;i<=tot;++i)
			{
				int ufa=findfa(edge[i].from),vfa=findfa(edge[i].to);
				if(ufa==vfa)continue;
				fa[ufa]=vfa;
				res+=edge[i].val;
			}
			return res;
		}
		inline void ReKruskal()
		{
			memcpy(tpedge,edge,sizeof edge);
			int m=tot;tot=0;
		    int cnt=dotnum;
			sort(tpedge+1,tpedge+tot+1,[](node a,node b){return a.val<b.val;});
			for(int i=1;i<=dotnum;++i)fa[i]=i;
			for(int i=1;i<=m;++i)
			{
		    	int ufa=findfa(tpedge[i].from),vfa=findfa(tpedge[i].to);
		    	if(ufa==vfa)continue;
	        	nval[++cnt]=tpedge[i].val;
				fa[ufa]=fa[vfa]=fa[cnt]=cnt; 
	        	addedge(cnt,ufa,1);
				addedge(cnt,vfa,1);
			}
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>prim_q;
		inline int Prim()
		{
		    memset(graph_dis,INF,sizeof graph_dis);
		    int cnt=0,res=0;
			graph_dis[1]=0;
			prim_q.push({0,1});
			while(!prim_q.empty())
			{
				if(cnt>=dotnum)break;
				int top=prim_q.top().second,tdis=prim_q.top().first;
				prim_q.pop();
				if(graph_vis[top])continue;
				graph_vis[top]=1;
				++cnt,res+=tdis;
				for(int i=hd[top];i;i=edge[i].nxt)
				{
			    	int to=edge[i].to,val=edge[i].val;
			    	if(val<graph_dis[to])graph_dis[to]=val,prim_q.push({val,to});
			    }
			}
			return cnt==dotnum?res:-1;
		}
		int beg[M];
		inline int Boruvka()
		{
			for(int i=1;i<=dotnum;++i)fa[i]=i;
			int res=0,knt=0;
			while(true)
			{
				int cnt=0;
				memset(graph_dis,INF,sizeof graph_dis);
				for(int i=1;i<=tot;++i)
				{
					int ufa=findfa(edge[i].from),vfa=findfa(edge[i].to);
					if(ufa==vfa||graph_vis[i])continue;
					++cnt;
					if(edge[i].val<graph_dis[ufa])graph_dis[ufa]=edge[i].val,beg[ufa]=i;
					if(edge[i].val<graph_dis[vfa])graph_dis[vfa]=edge[i].val,beg[vfa]=i;
				}
				if(!cnt||knt==dotnum-1)break;
				for(int i=1;i<=dotnum;++i)
				{
					int ufa=findfa(edge[beg[i]].from),vfa=findfa(edge[beg[i]].to);
					if(graph_dis[i]==INF||ufa==vfa||graph_vis[beg[i]])continue;
					graph_vis[beg[i]]=1;
					fa[ufa]=vfa;
					res+=edge[beg[i]].val;
					++knt;
				}
			}
			return knt==dotnum-1?res:-1;
		}
		inline void floyd()
		{
			for(int k=1;k<=dotnum;++k)
		        for(int i=1;i<=dotnum;++i)
		            for(int j=1;j<=dotnum;++j)
		                floyd_mp[i][j]=floyd_mp[j][i]=min(floyd_mp[i][j],floyd_mp[i][k]+floyd_mp[k][j]);
		}
		inline void Warshall()
		{
			for(int k=1;k<=dotnum;++k)
		        for(int i=1;i<=dotnum;++i)
		            for(int j=1;j<=dotnum;++j)
		                floyd_mp[i][j]|=floyd_mp[i][k]&floyd_mp[k][j];
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>dijk_q;
		inline void dijkstra(int s,int *dist)
		{
			for(int i=0;i<M;++i)dist[i]=INF;
			memset(graph_vis,0,sizeof graph_vis);
			dist[s]=0;
			dijk_q.push({0,s});
		    while(!dijk_q.empty())
		    {
		        int top=dijk_q.top().second;
				dijk_q.pop();
		        if(graph_vis[top])continue;
		        graph_vis[top]=1;
		        for(int i=hd[top];i;i=edge[i].nxt)
		        {
		            int to=edge[i].to;
		            if(dist[to]>dist[top]+edge[i].val)
		            {
		                dist[to]=dist[top]+edge[i].val;
		                if(!graph_vis[to])dijk_q.push({dist[to],to});
		            }
		        }
		    }
		}
		queue<int>spfa_q;
		int spfa_dep[M];
		inline bool SPFA(int s,int *dist)
		{
			for(int i=0;i<M;++i)dist[i]=INF;
			memset(graph_vis,0,sizeof graph_vis);
			memset(spfa_dep,0,sizeof spfa_dep);
			dist[s]=0;
			graph_vis[s]=1;
			spfa_q.push(s);
			while(!spfa_q.empty())
			{  
				int top=spfa_q.front();
				spfa_q.pop();
				graph_vis[top]=0;
				for(int i=hd[top];i;i=edge[i].nxt)
				{
					if(dist[top]+edge[i].val<dist[edge[i].to])
					{
						dist[edge[i].to]=dist[top]+edge[i].val;
						spfa_dep[edge[i].to]=spfa_dep[top]+1;
						if(spfa_dep[edge[i].to]>=dotnum)
						{
							while(!spfa_q.empty())spfa_q.pop();
							return 0;
						}
						if(!graph_vis[edge[i].to])
						{
							graph_vis[edge[i].to]=1;
							spfa_q.push(edge[i].to);
						}
					}
				}
			}
			return 1;
		}
		int john_dis[M],john_dist[M];
		inline bool Johnson(int*ans)
		{
			for(int i=1;i<=dotnum;++i)addedge(0,i,0);
			++dotnum; 
			if(!SPFA(0,john_dis))return 0;
			--dotnum;
			for(int pos=1;pos<=dotnum;++pos)
    			for(int i=hd[pos];i;i=edge[i].nxt)
					edge[i].val+=john_dis[pos]-john_dis[edge[i].to];
			for(int i=1;i<=dotnum;++i)
			{
				dijkstra(i,john_dist);
				for(int j=1;j<=dotnum;++j)
				{
					if(john_dist[j]==INF)ans[i]+=j*jINF;
					else ans[i]+=j*(john_dist[j]+john_dis[j]-john_dis[i]);
				}
			}
			return 1;
		}
		int tim,low[M],dfn[M];
		stack<int>tst;
		vector<vector<int>>EBCC_res,DBCC_res,SCC_res;
		inline void EBCC_dfs(int pos,int in)
		{
			low[pos]=dfn[pos]=++tim;
			tst.push(pos),graph_vis[pos]=1;
			for(int i=hd[pos];i;i=edge[i].nxt)
			{
				int to=edge[i].to;
				if((i+1)==((in+1)^1))continue;
				if(!dfn[to])EBCC_dfs(to,i),low[pos]=min(low[pos],low[to]);
				else if(graph_vis[to])low[pos]=min(low[pos],dfn[to]);
			}
			if(dfn[pos]==low[pos])
			{
				vector<int>tp;
				tp.push_back(pos);
				while(tst.top()!=pos)tp.push_back(tst.top()),graph_vis[tst.top()]=0,tst.pop();
				tst.pop(),EBCC_res.push_back(tp);
			}
		}
		inline vector<vector<int>>EBCC()
		{
			for(auto&i:EBCC_res)i.clear();
			EBCC_res.clear();
			tim=0;
			memset(dfn,0,sizeof dfn);
			memset(low,0,sizeof low);
			memset(graph_vis,0,sizeof graph_vis);
			for(int i=1;i<=dotnum;++i)if(!dfn[i])EBCC_dfs(i,0);
			return EBCC_res;
		}
		inline void DBCC_dfs(int pos)
		{
			dfn[pos]=low[pos]=++tim;
			tst.push(pos);
			if(!ind[pos])
			{
				vector<int>tp;
				tp.emplace_back(pos);
				DBCC_res.emplace_back(tp);
				return;
			}
			for(int i=hd[pos];i;i=edge[i].nxt)
			{
				int to=edge[i].to;
				if(!dfn[to])
				{
					DBCC_dfs(to);
					low[pos]=min(low[pos],low[to]);
					if(low[to]>=dfn[pos])
					{
						vector<int>tp;
						int top;
						do
						{
							top=tst.top();
							tp.push_back(top);
							tst.pop();
						}
						while(top!=to);
						tp.emplace_back(pos);
						DBCC_res.emplace_back(tp);
					}
				}
				else low[pos]=min(low[pos],dfn[to]);
			}
		}
		inline vector<vector<int>>DBCC()
		{
			for(auto&i:DBCC_res)i.clear();
			DBCC_res.clear();
			tim=0;
			memset(dfn,0,sizeof dfn);
			memset(low,0,sizeof low);
			memset(graph_vis,0,sizeof graph_vis);
			for(int i=1;i<=dotnum;++i)if(!dfn[i])DBCC_dfs(i);
			return DBCC_res;
		}
		inline void SCC_dfs(int pos,int*scc)
		{
			dfn[pos]=low[pos]=++tim;
			tst.push(pos),graph_vis[pos]=1;
			for(int i=hd[pos];i;i=edge[i].nxt)
			{
				int to=edge[i].to;
				if(!dfn[to])
				{
					SCC_dfs(to,scc);
					low[pos]=min(low[pos],low[to]);
				}
				else if(graph_vis[to])low[pos]=min(low[pos],dfn[to]);
			}
			if(dfn[pos]==low[pos])
			{
				vector<int>tp;
				int cnt=SCC_res.size();
				while(tst.top()!=pos)
				{
					tp.emplace_back(tst.top());
					scc[tst.top()]=cnt;
					graph_vis[tst.top()]=0;
					tst.pop();
				}
				tp.emplace_back(tst.top());
				scc[tst.top()]=cnt;
				graph_vis[tst.top()]=0;
				tst.pop();
				SCC_res.emplace_back(tp);
			}
		}
		inline vector<vector<int>>SCC(int*scc)
		{
			for(auto&i:SCC_res)i.clear();
			SCC_res.clear();
			vector<int>zero;
			SCC_res.emplace_back(zero);
			tim=0;
			memset(dfn,0,sizeof dfn);
			memset(low,0,sizeof low);
			for(int i=1;i<=dotnum;++i)if(!dfn[i])SCC_dfs(i,scc);
			return SCC_res;
		}
	};
}
using namespace Wilder_Graph;
int dg[1000010];
bool dvis[1000010];
signed main()
{
	Graph g;
	int n=read(),m=read();
	g.build(n,m,1,0);
    auto syh=g.SCC(dg);
    cout<<syh.size()-1<<endl;
	for(auto&i:syh)sort(i.begin(),i.end());
	for(int i=1;i<=n;++i)
	{
		if(dvis[dg[i]])continue;
		dvis[dg[i]]=1;
		for(auto j:syh[dg[i]])cout<<j<<" ";
		cout<<'\n';
	}
    return 0;
}

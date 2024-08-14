#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 510010
#define maxm 200010
#define maxk 12
using namespace std;
struct Edge{
	int next,to,val;
}edge[maxm*2*11];
struct priority{
	int dis,id;
	bool operator <(const priority &a)const{
		return a.dis<dis;
	}
};
priority_queue<priority>q;
int head[maxn],cnt,n,m,k,start,END,dis[maxn],vis[maxn];
void addedge(int from,int to,int val){
	edge[++cnt].next=head[from];
	edge[cnt].to=to;
	edge[cnt].val=val;
	head[from]=cnt;
	return;
}
signed main(){
	cin>>n>>m>>k>>start>>END;
	for(int i=1;i<=m;++i){
		int f,t,v;
		cin>>f>>t>>v;
		for(int ccf=0;ccf<k;++ccf){
			addedge(f+ccf*n,t+ccf*n,v);
			addedge(t+ccf*n,f+ccf*n,v);
			addedge(f+ccf*n,t+(ccf+1)*n,0);
			addedge(t+ccf*n,f+(ccf+1)*n,0);
		}
		addedge(f+n*k,t+n*k,v);
		addedge(t+n*k,f+n*k,v);
	}
    for(int i=1;i<=k;++i){addedge(END+(i-1)*n,END+i*n,0);}
	memset(dis,INF,sizeof dis);
	dis[start]=0;
	q.push((priority){0,start});
	while(!q.empty()){
		priority res=q.top();
		q.pop();
		if(!vis[res.id]){
			vis[res.id]=1;
			for(int ccf=head[res.id];ccf;ccf=edge[ccf].next){
				int v=edge[ccf].to,val=edge[ccf].val;
				if(dis[v]>res.dis+val){
					dis[v]=res.dis+val;
					if(!vis[v])q.push((priority){dis[v],v});
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=k;++i)ans=min(ans,dis[i*n+END]);
	cout<<ans;
	return 0;
}

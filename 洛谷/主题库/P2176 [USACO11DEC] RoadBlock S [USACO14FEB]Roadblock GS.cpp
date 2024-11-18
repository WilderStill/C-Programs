#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 10145
using namespace std;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}
vector<pair<int,int> >edge[M];
int n,m,syh,dis[M],f,to[M];
int dijkstra()
{
    for(int i=1;i<=f;i++)dis[i]=INF;
    priority_queue<pair<int,int>>q;
    dis[f]=0;
    q.push(make_pair(-dis[f],f));
    while(!q.empty())
    {
        int now=q.top().second;
        q.pop();
        for(int i=0;i<edge[now].size();i++)
        {
            int v=edge[now][i].first;
            if(dis[v]>dis[now]+edge[now][i].second)
            {
                dis[v]=dis[now]+edge[now][i].second;
                to[v]=now;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
    return dis[1];
}
int main()
{
    n=read(),m=read();f=n;
    for(int i=1;i<=m;i++)
    {
        int x=n-read()+1,y=n-read()+1,z=read();
        edge[x].push_back(make_pair(y,z));
        edge[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=n;i++)to[i]=-1;
    int ans=dijkstra();
    stack<int>s;
    s.push(1);
    int t=1;
    while(to[t]!=-1)
    {
        s.push(to[t]);
        t=to[t];
    }
    int hd=s.top(),nt;
    s.pop();
    while(!s.empty())
    {
        nt=s.top();
        s.pop();
        int nt1,nt2,hd1,hd2;
        for(int i=0;i<edge[hd].size();i++)
	        if(edge[hd][i].first==nt)
	        {
	           hd1=edge[hd][i].second;
	           edge[hd][i].second=2*hd1;
	           hd2=i;
	        }
        for(int i=0;i<edge[nt].size();i++)
	        if(edge[nt][i].first==hd)
	        {
	           nt1=edge[nt][i].second;
	           edge[nt][i].second=2*nt1;
	           nt2=i;
	        }
        syh=max(syh,dijkstra());
        edge[hd][hd2].second=hd1;
		edge[nt][nt2].second=nt1;
        hd=nt;
		if(1.*clock()/CLOCKS_PER_SEC>=0.99)break;
    }
    write(syh-ans);
    return 0;
}

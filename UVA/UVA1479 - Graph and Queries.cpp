#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
int t,n,m,cnt,ans,tot,num[20010],fa[20010];
char op;
bool del[60010];
tree<pair<int,int>,null_type,greater<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>tr[20010];
struct node
{
    int u,v;
}edge[60010];
struct query
{
    int id,x,k;
}qry[500010];
inline int find(int x){return fa[x]<0?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y)return;
    if(fa[x]>fa[y])swap(x,y);
    for(auto it=tr[y].begin();it!=tr[y].end();++it)tr[x].insert(*it);
    tr[y].clear();
    fa[x]+=fa[y];
    fa[y]=x;
}
signed main()
{
	cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    while(cin>>n>>m&&n&&m)
	{
		cnt=ans=tot=0;
		memset(del,0,sizeof del);
		for(int i=1;i<=n;++i)tr[i].clear(),fa[i]=-1;
        for(int i=1;i<=n;++i)cin>>num[i];
        for(int i=1;i<=m;++i)cin>>edge[i].u>>edge[i].v;
        while(cin>>op)
		{
			if(op=='E')break;
			int x,k;
            if(op=='D')
			{
				cin>>x;
                del[x]=1;
                qry[++cnt]={1,x};
            }
			if(op=='C')
			{
				cin>>x>>k;
                qry[++cnt]={2,x,num[x]};
                num[x]=k;  
            }
			if(op=='Q')
			{
                cin>>x>>k;
                ++tot;
                qry[++cnt]={3,x,k};
            }
        }
        for(int i=1;i<=n;++i)tr[i].insert(make_pair(num[i],i));
        for(int i=1;i<=m;++i)
            if(!del[i])
                merge(edge[i].u,edge[i].v);
        for(int i=cnt;i;--i)
		{
			if(qry[i].id==1)merge(edge[qry[i].x].u,edge[qry[i].x].v);
			if(qry[i].id==2)
			{
                auto it=tr[find(qry[i].x)].find(make_pair(num[qry[i].x],qry[i].x));
                tr[find(qry[i].x)].erase(it);
                tr[find(qry[i].x)].insert(make_pair(num[qry[i].x]=qry[i].k,qry[i].x));
            }
            if(qry[i].id==3)
            {
            	if(tr[find(qry[i].x)].size()>=qry[i].k)
                    ans+=tr[find(qry[i].x)].find_by_order(qry[i].k-1)->first;
			}
        }
        cout<<"Case "<<++t<<": "<<fixed<<setprecision(6)<<ans*1.0/tot<<'\n';
    }
    return 0;
}
/*
3 3
10
20
30
1 2
2 3
1 3
D 3
Q 1 2
Q 2 1
D 2
Q 3 2
C 1 50
Q 1 1
E

3 3
10
20
20
1 2
2 3
1 3
Q 1 1
Q 1 2
Q 1 3
E

*/

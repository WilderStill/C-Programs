#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define M 114514
#define ll long long
using namespace std;
using namespace __gnu_pbds;
tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>t[100005];
ll n,m,a[M],op,g,sd[M],f[M],ans,Save[M];
int oj[M*114];
vector<int>td[M];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void q3(int o4,int o5)
{
	if(find(o4)==find(o5))return;
	if(t[f[o4]].size()<t[f[o5]].size())swap(o4,o5);
	while(t[f[o5]].size())
	{
		auto it=t[f[o5]].begin();
		t[f[o4]].insert(*it);
		t[f[o5]].erase(it);
	}
	Save[f[o4]]+=Save[f[o5]],f[f[o5]]=f[o4];
}
void bfs(int x)
{
	for(int i=0;i<td[x].size();i++)
	{
		bfs(td[x][i]);
		q3(td[x][i],x);
	}
	while(Save[find(x)]>m)
	{
		auto it=(--t[f[x]].end());
		Save[f[x]]-=*it,t[f[x]].erase(it);
	}
	op=sd[x]*t[f[x]].size();
	ans=max(ans,op);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&op,&a[i],&sd[i]);
		f[i]=i,td[op].push_back(i),t[i].insert(a[i]),Save[i]=a[i];
	}
	bfs(td[0][0]);
	cout<<ans;
    return 0;
}

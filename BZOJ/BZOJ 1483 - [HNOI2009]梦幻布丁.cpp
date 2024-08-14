#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
tree<ll,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>t[1145141];
ll n,m,a[114514],op,ans,x,y,db,f[1145141];
void sd(int x,int id)
{
	t[x].insert(id);
	auto it=t[x].lower_bound(id+1),ti=t[x].lower_bound(id-1);
	if((*it!=id+1)&&(!(*ti)||*ti!=id-1))ans++;
	if((*it==id+1)&&(*ti&&*ti==id-1))ans--;
}
void q3(int x,int id)
{
	auto it=t[x].lower_bound(id+1),ti=t[x].lower_bound(id-1);
	if((*it==id+1)&&(*ti&&*ti==id-1))ans++;
	if((*it!=id+1)&&(!(*ti)||*ti!=id-1))ans--;
	t[x].erase(id);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sd(a[i],i);
	}
	for(int i=0;i<=1145141;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&op);
		if(op==2)printf("%lld\n",ans);
		else
		{
			scanf("%lld%lld",&x,&y);
			if(f[x]==f[y])continue;
			db=0;
			if(t[f[x]].size()>t[f[y]].size())db=1,swap(x,y);
			while(!t[f[x]].empty())
			{
				auto it=t[f[x]].begin();
				q3(f[x],*it);
				sd(f[y],*it);
			}
			if(db==1)swap(f[x],f[y]);
		}
	}
    return 0;
}

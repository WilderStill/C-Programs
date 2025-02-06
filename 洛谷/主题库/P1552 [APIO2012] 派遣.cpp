#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>tr[100010];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
ll n,m,ans,fa[100010],size[100010],l[100010];
vector<int>mp[100010];
inline int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
inline void merge(int x,int y)
{
	if(findfa(x)==findfa(y))return;
	if(tr[fa[x]].size()<tr[fa[y]].size())swap(x,y);
	while(!tr[fa[y]].empty())
	{
		auto it=tr[fa[y]].begin();
		tr[fa[x]].insert(*it);
		tr[fa[y]].erase(it);
	}
	size[fa[x]]+=size[fa[y]];
	fa[fa[y]]=fa[x];
}
inline void search(int pos)
{
	for(auto to:mp[pos])
	{
		search(to);
		merge(to,pos);
	}
	while(size[findfa(pos)]>m)
	{
		auto it=(--tr[fa[pos]].end());
		size[fa[pos]]-=*it;
		tr[fa[pos]].erase(it);
	}
	ll tp=l[pos]*tr[fa[pos]].size();
	ans=max(ans,tp);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		ll x=read(),y=read();l[i]=read();
		fa[i]=i;
		mp[x].emplace_back(i);
		tr[i].insert(y);
		size[i]=y;
	}
	search(mp[0][0]);
	write(ans);
    return 0;
}

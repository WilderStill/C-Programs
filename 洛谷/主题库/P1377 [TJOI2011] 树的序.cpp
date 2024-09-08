#include<bits/stdc++.h>
#define ll long long
#define M 10000100
using namespace std;
ll n,lson[M],rson[M],stk[M],ans[M];
struct node
{
	ll id,val;
}p[M];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
void dfs(int rt)
{
	if(rt>n)return;
	cout<<ans[rt]<<" ";
	if(lson[rt])dfs(lson[rt]);
	if(rson[rt])dfs(rson[rt]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cin.tie(0);
	int top=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>p[i].val,p[i].id=i;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		int k=top;
		while(k&&p[stk[k]].id>p[i].id)--k;
		ans[i]=p[i].val;
		lson[i]=rson[stk[k]];
        rson[stk[k]]=i;
		stk[++k]=i;
		top=k;
	}
	dfs(rson[0]);
	return 0;
}

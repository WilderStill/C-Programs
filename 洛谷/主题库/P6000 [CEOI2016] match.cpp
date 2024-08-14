#include<bits/stdc++.h>
#define M 100010
using namespace std;
typedef long long ll;
const int base=127;
struct node
{
	char ch;
	ll hash;
	node(char _ch,ll _hash){ch=_ch,hash=_hash;}
};
char s[M],ans[M];
ll h[M],lsh[M],sz[M];
stack<node>stk;
vector<ll>v[M];
void dfs(int l,int r)
{
	if(l>r)return;
	ans[l]='(';
	int tp=upper_bound(v[h[l]].begin()+sz[l],v[h[l]].end(),r-1)-v[h[l]].begin()-1;
	int pos=v[h[l]][tp]+1;
//	cout<<pos<<endl;
	ans[pos]=')';
	dfs(l+1,pos-1);
	dfs(pos+1,r);
}
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	s[0]=s[n+1]='&';
	for(int i=1;i<=n;++i)
	{
		if(!stk.empty())
		{
			if(stk.top().ch==s[i])stk.pop();
			else stk.push(node(s[i],stk.top().hash*base+s[i]));
		}
		else stk.push(node(s[i],s[i]));
		if(stk.empty())h[i]=0;
		else h[i]=stk.top().hash;
	}
	if(!stk.empty())
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)lsh[i]=h[i];
	sort(lsh+1,lsh+n+1);
	int m=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;++i)
	{
		h[i]=lower_bound(lsh+1,lsh+m+1,h[i])-lsh;
		v[h[i]].push_back(i);
		sz[i]=v[h[i]].size();
	}
	dfs(1,n);
	for(int i=1;i<=n;++i)putchar(ans[i]);
    return 0;
}


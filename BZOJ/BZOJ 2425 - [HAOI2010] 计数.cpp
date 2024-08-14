#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[55],bit[55],len;
map<vector<ll>,ll>f[55][2];
map<vector<ll>,bool>viss[55][2];
vector<ll>v;
ll dfs(ll n,bool is_max)
{
    if(n>len)return 1;
    if(viss[n][is_max][v])return f[n][is_max][v];
    ll mx=is_max?bit[n]:9,ans=0;
    for(ll i=0;i<=mx;++i)
    	if(v[i]<vis[i])
    	{
    		++v[i];
	        ans+=dfs(n+1,is_max&&i==mx);
	        --v[i];
		}	
    f[n][is_max][v]=ans;
    viss[n][is_max][v]=1;
    return ans;
}
ll dp_(char s[])
{
	len=strlen(s+1);
    for(ll i=1;i<=len;++i)bit[i]=s[i]-'0',vis[bit[i]]++;
    for(ll i=0;i<=9;++i)v.push_back(0);
    return dfs(1,1);
}
char num[55];
int main()
{
    scanf("%s",num+1);
    printf("%lld",dp_(num)-1);
    return 0;
}

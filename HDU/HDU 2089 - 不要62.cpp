#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[144],f[144][10];
ll dfs(int n,int pre,bool is_max)
{
    if(!n)return 1;
    if(!is_max&&~f[n][pre])return f[n][pre];
    int m=is_max?bit[n]:9;
    ll ans=0;
    for(int i=0;i<=m;i++)
        if(!((pre==6&&i==2)||i==4))ans+=dfs(n-1,i,is_max&&i==m);
    if(!is_max)f[n][pre]=ans;
    return ans;
}
ll dp_(ll x)
{
    int len=0;
    while(x)
    {
        bit[++len]=x%10;
        x/=10;
    }
    return dfs(len,0,1);
}
int main()
{
    ll m,n;
	memset(f,-1,sizeof(f));
    while(scanf("%lld%lld",&n,&m))
    {
    	if(!n&&!m)return 0;
        printf("%lld\n",dp_(m)-dp_(n-1));
    }
}

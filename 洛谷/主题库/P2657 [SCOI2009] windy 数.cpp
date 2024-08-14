#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[144],f[144][10];
ll dfs(int n,int pre,bool st,bool is_max)
{
    if(!n)return 1;
    if(!is_max&&!st&&~f[n][pre])return f[n][pre];
    int m=is_max?bit[n]:9;
    ll ans=0;
    for(int i=0;i<=m;i++)
        if(abs(pre-i)>=2)
		{
			if(st&&!i)ans+=dfs(n-1,-2,1,is_max&&i==m);
			else ans+=dfs(n-1,i,0,is_max&&i==m);
		}
    if(!is_max&&!st)f[n][pre]=ans;
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
    return dfs(len,-2,1,1);
}
int main()
{
    ll m,n;
	memset(f,-1,sizeof(f));
    scanf("%lld%lld",&n,&m);
    printf("%lld",dp_(m)-dp_(n-1));
}

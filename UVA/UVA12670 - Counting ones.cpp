#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[144],f[141][114];
ll dfs(ll n,int sum,bool lead)
{
	if(!n)return sum;
	if(!lead&&~f[n][sum])return f[n][sum];
	ll m=lead?bit[n]:1,ans=0;
	for(int i=0;i<=m;++i)ans+=dfs(n-1,sum+i,lead&&i==m);
	if(!lead)f[n][sum]=ans;
	return ans;
}
ll dp_(ll x)
{
    ll len=0;
    while(x)
    {
        bit[++len]=x&1;
        x>>=1;
    }
    return dfs(len,0,1);
}
int main()
{
    ll m,n;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
    	memset(f,-1,sizeof(f));
	    printf("%lld\n",dp_(m)-dp_(n-1));
	}
    return 0;
}

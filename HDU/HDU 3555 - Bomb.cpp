#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[144],f[144][2];
ll dfs(int n,int pre,bool is_max)
{
    if(!n)return 1;
    if(!is_max&&~f[n][pre==4])return f[n][pre==4];
    int m=is_max?bit[n]:9;
    ll ans=0;
    for(int i=0;i<=m;i++)
        if(!(pre==4&&i==9))ans+=dfs(n-1,i,is_max&&i==m);
    if(!is_max){f[n][pre==4]=ans;}
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
    ll T,n;
    scanf("%lld",&T);
	memset(f,-1,sizeof(f));
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",n-dp_(n)+1);
    }
}

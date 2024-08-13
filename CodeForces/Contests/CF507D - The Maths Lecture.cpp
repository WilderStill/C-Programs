#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll len,m,p,f[1145][105][2][2],fp[1145];
ll dfs(int n,int sum,bool has,bool pre0,bool is_max)
{
    if(n==len)return has;
	if(!is_max&&~f[n][sum][has][pre0])return f[n][sum][has][pre0];
	int ans=0;
	for(int i=0;i<=9;++i)
	{
		if(!i&&n==len-1)continue;
		if(!i)ans+=dfs(n+1,(sum+i*fp[n]%m)%m,has|(pre0&&(sum+i*fp[n]%m)%m==0),pre0,0);
		else ans+=dfs(n+1,(sum+i*fp[n]%m)%m,has|((sum+i*fp[n]%m)%m==0),1,0);
		ans%=p;
	}
	if(!is_max)f[n][sum][has][pre0]=ans;
	return ans;
}
int main()
{
	memset(f,-1,sizeof(f));
    scanf("%lld%lld%lld",&len,&m,&p);
    fp[0]=1;
    for(ll i=1;i<=len;++i)fp[i]=fp[i-1]*10%m;
    printf("%lld",dfs(0,0,0,0,0));
}

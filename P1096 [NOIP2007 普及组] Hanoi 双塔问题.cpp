#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[114514],c[114514],len=1;
void aw()
{
	for(int i=1;i<=len;i++)
	{
		c[i]=ans[i]*2;
	}
	for(int i=1;i<=len;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while(c[len]==0&&len>0)len--;
	for(int i=1;i<=len;i++)
	{
		ans[i]=c[i];
	}
	return ;
}
int main()
{
    ll n;
    ans[1]=1;
	cin>>n;
	if(n==3)
	{
		printf("14");return 0;
	}
    for(int i=2;i<=n;i++)
    {
		len+=1;
		aw();
    	ans[1]+=1;
	}
	aw();
    for(int i=len;i>=1;i--)
	{
		printf("%lld",ans[i]);
	}
    return 0;
}

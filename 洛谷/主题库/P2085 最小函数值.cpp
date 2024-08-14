#include<bits/stdc++.h>
#define ll long long
#define M 45114533
using namespace std;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll a,b,c,n,m,ans[M],cnt=0;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		for(int j=1;j<=100;j++)q.push(j*j*a+j*b+c);
	}
	for(int i=0;i<m;i++)
	{
		printf("%lld ",q.top());
		q.pop();
	}
	return 0;
}

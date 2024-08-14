#include<bits/stdc++.h>
#define ll long long
#define db double
#define INF 0x3f3f3f3f
using namespace std;
ll n,m,a[11451411];
double res=INF,v=0.0;
priority_queue<ll,vector<ll>,greater<ll> >q;
int main()
{
	mt19937 md(time(0));
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),v+=a[i];
	v=v/(db)m;
	while((db)clock()/CLOCKS_PER_SEC<=0.9979)
	{
		shuffle(a+1,a+n+1,md);
		for(ll i=1;i<=m;i++)q.push(0);
		for(ll i=1;i<=n;i++)q.push(q.top()+a[i]),q.pop();
		double sum=0.0;
		while(!q.empty())
		{
			ll x=q.top();q.pop();
			sum=sum+pow(x-v,2);
		}
		res=min(res,sum);
	}
	printf("%.2lf\n",sqrt(res/(db)m));
	return 0;
}

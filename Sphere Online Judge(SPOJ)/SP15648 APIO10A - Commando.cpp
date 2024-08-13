#include<bits/stdc++.h>
#define M 1000100
#define ll long long
#define ld long double
using namespace std;
ll n,a,b,c,f[M],sum[M],hd,tl,q[M];
ll X(int i1){return sum[i1];}
ll Y(int i1){return f[i1]+a*sum[i1]*sum[i1]-b*sum[i1];}
ld k(int i1,int i2)
{
	return (ld)(Y(i2)-Y(i1))/(X(i2)-X(i1));
}
int T;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b>>c;
		sum[0]=0;
		for(int i=1;i<=n;++i)
		{
			ll x;
			cin>>x;
			sum[i]=x+sum[i-1];
		}
		hd=tl=0;
		for(int i=1;i<=n;++i)
		{
			while(hd<tl&&k(q[hd+1],q[hd])>2*a*sum[i])++hd;
			f[i]=f[q[hd]]+a*(sum[i]-sum[q[hd]])*(sum[i]-sum[q[hd]])+b*(sum[i]-sum[q[hd]])+c;
			while(hd<tl&&k(i,q[tl])>=k(q[tl-1],q[tl]))--tl;
			q[++tl]=i;
		}
		cout<<f[n]<<'\n';
	}
	return 0;
}

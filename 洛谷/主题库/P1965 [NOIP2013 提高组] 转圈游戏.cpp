#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x,ans;
int qpow(int x1,int y)
{
	int res=1;
	int x=x1;
	while(y)
	{
		if(y&1) res=(res*x)%n;
		x=(x*x)%n;
		y>>=1;
	}
	return res;
}
signed main()
{
	cin>>n>>m>>k>>x;
	ans=(x%n+m%n*qpow(10,k)%n)%n;
	cout<<ans;
	return 0;
}

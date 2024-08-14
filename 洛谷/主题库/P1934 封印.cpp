#include<bits/stdc++.h>
#define ll long long
#define gf(a,b) a*b*b
using namespace std;
ll n,t,a[114514],f[114514],b[114514];
int main()
{
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+gf(a[i],n);
		for(int k=1;k<i;k++)
			if(a[i]+a[k]<=t)
				f[i]=min(f[i],f[k-1]+(a[i]+a[k])*(b[i]-b[k-1]));	
	}
	//for(int i=1;i<=n;i++)
//		printf("%lld ",f[i]);
	printf("%lld",f[n]);
	return 0;
}

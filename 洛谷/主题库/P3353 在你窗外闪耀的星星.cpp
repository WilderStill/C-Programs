#include <bits/stdc++.h>
using namespace std;
int ans=0,a[1000000],n,w,sum,l=100001,r=0;
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1,x,b;i<=n;i++)
	{
		scanf("%d%d",&x,&b);
		a[x]+=b;
		l=min(l,x);
		r=max(r,x);
	}	
	for(int i=0;i<w;i++)
		if(l+i<=100000)
			ans+=a[l+i];
	sum=ans;
	for(int i=l+1;i<=r-w+1;i++)
	{
		sum-=a[i-1];
		sum+=a[i+w-1];
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}

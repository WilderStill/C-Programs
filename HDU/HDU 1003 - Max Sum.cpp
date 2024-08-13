#include<bits/stdc++.h>
#define M 11451411
using namespace std;
int T,n,a[M],f[M],ans=-M;
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		ans=-M;
		int r=1,l=1,rans=1,lans=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
	    	scanf("%d",&a[i]);
	    	if(f[i-1]>=0)
	    	{
	    		f[i]=f[i-1]+a[i],
				r=i; 
			}
			else
			{
				f[i]=a[i];
				r=l=i;
			}
			if(ans<f[i])
			{
				ans=f[i];
				rans=r;
				lans=l;
			}
		}
		printf("Case %d:\n",t);
		printf("%d %d %d\n",ans,lans,rans);
	}
	return 0;
}

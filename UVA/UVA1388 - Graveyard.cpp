#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		double syh=0.00;
		for(int i=1;i<n;++i)
		{
			double dg=1.0*i/n*(m+n);
			syh+=fabs(dg-floor(dg+0.5))/(m+n);
		}
		printf("%0.4lf\n",syh*10000);
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

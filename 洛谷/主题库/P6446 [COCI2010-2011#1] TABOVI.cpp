#include<bits/stdc++.h>
using namespace std;
long long n,a[1010],ans,tmp;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)
	{
		long long h;
		scanf("%lld",&h);
		a[i]=h-a[i];
	}
    for(int i=1;i<=n;++i)
    {
    	if(a[i]>0)
    	{
    		if(a[i-1]>0)ans+=max(a[i]-a[i-1],0ll);
    		else ans+=a[i];
		}
		else
		{
			if(a[i-1]<0)ans-=min(a[i]-a[i-1],0ll);
			else ans-=a[i];
		}
    }
    printf("%lld",ans);
    return 0; 
}

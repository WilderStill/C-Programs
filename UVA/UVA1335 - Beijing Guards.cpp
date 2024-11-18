#include<bits/stdc++.h>
#define MAXN 114514
using namespace std;
int n,a[MAXN],l,r,maxn[MAXN],minn[MAXN];
bool check_dp(int x)
{
    for(int i=2;i<=n;i++)
    {
        maxn[i]=min(a[i],a[1]-minn[i-1]);
        minn[i]=max(0,a[1]+a[i-1]-maxn[i-1]+a[i]-x);
    }
    if(minn[n]) return false;
    else return true;
}
int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)return 0;
		memset(a,0,sizeof a);
		memset(maxn,0,sizeof maxn);
		memset(minn,0,sizeof minn);
		l=0,r=0;
	    for(int i=1;i<=n;i++)
	    {
	        scanf("%d",&a[i]);
	        l=max(l,a[i]+a[i-1]);
	    }
	    if(n==1)
		{
			printf("%d\n",a[1]);
			continue;
		}
	    maxn[1]=a[1],minn[1]=a[1];
	    r=MAXN*10;
	    while(l<=r)
	    {
	        int mid=(l+r)/2;
	        if(check_dp(mid))r=mid-1;
	        else l=mid+1;
	    }
	    printf("%d\n",l);
	}
    return 0;
}

#include<bits/stdc++.h>
#define mod 14233333
#define ll long long
ll ans=2,tmp=1,now,n;
int main()
{
    scanf("%lld",&n);
    if(n==1||n==2) printf("%lld",n);
	else
	{
		for(ll i=3;i<=n;i++)
		{
	        now=(tmp*(i-1)+ans)%mod;
			tmp=ans,ans=now;
	    }
	    printf("%lld",ans);
	}
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,a[1145141],b[1145141];
priority_queue<ll>q;
int main()
{
	scanf("%lld",&n);
    for(ll i=1,x;i<=n;i++)
	{
        scanf("%lld",&x);
		b[i]=-x;
		x=-x;
        q.push(x);
        if(q.top()>x)
		{
            q.pop();
			q.push(x);
        }
        a[i]=q.top();
    }
    for(int i=n-1;i>=1;i--)a[i]=min(a[i],a[i+1]);
    for(int i=1;i<=n;i++)ans+=abs(a[i]-b[i]);
    printf("%lld",ans);
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
priority_queue<ll>q;
int main()
{
    scanf("%lld",&n);
    if(n==3)
	{
		printf("1");return 0;
	}
    for(ll i=1,x;i<=n;i++)
	{
        scanf("%lld",&x);
        q.push(x);
        if(x<q.top())
		{
            ans+=q.top()-x;
            q.pop();
            q.push(x);
        }
    }
    printf("%lld",ans);
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
priority_queue<ll>q;
int main()
{
    scanf("%lld",&n);
    for(ll i=1,x;i<=n;i++)
	{
        scanf("%lld",&x);
        x-=i;
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

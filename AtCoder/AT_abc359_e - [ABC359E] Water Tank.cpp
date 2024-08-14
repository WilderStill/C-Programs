#include<bits/stdc++.h>
#define ll long long
const ll mod=998244353;
using namespace std;
ll n,h[11451411],f[11451411],ans[11451411];
stack<ll>dg;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&h[i]);
    for(int i=1;i<=n;++i)
    {
        while(!dg.empty()&&h[dg.top()]<=h[i])dg.pop();
        if(dg.empty())f[i]=0;
        else f[i]=dg.top();
        dg.push(i);
    }
    ans[0]=0;
    for(int i=1;i<=n;++i)
    {
        ans[i]=(i-f[i])*h[i]+ans[f[i]];
        printf("%lld ",ans[i]+1);
    }
    return 0;
}

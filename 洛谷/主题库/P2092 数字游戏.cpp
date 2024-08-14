#include<bits/stdc++.h>
#define ll long long 
using namespace std;
queue<ll>q;
ll n;
int main()
{
    scanf("%lld",&n);
    for(ll i=2;i*i<=n;i++)while(!(n%i))q.push(i),n/=i;
    if(n!=1)q.push(n);
    if(q.size()==1)puts("1"),puts("0");
    else if(q.size()==2)puts("2");
    else
    {
        puts("1");
		ll top1=q.front();q.pop();
		ll top2=q.front();
        printf("%lld\n",top1*top2);
    }
    return 0;
}

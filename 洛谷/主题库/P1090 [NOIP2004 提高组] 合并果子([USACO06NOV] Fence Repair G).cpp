#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1145141],ans;
queue<ll>q1,q2;
ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
ll add()
{
	ll tmp;
	if(q2.empty()||(!q1.empty()&&q1.front()<q2.front()))
	{
		tmp=q1.front();
		q1.pop();
	}
	else
	{
		tmp=q2.front();
		q2.pop();
	}
	return tmp;
}
int main()
{
	n=read();
	for(ll i=1,tmp;i<=n;i++)
	{
		a[read()]++;
	}
	for(ll i=1;i<=114514;i++)
		while(a[i]--)
			q1.push(i);
	while(--n)
	{
		ll b=add(),c=add();
		ans+=b+c;
		q2.push(b+c);
	}
	printf("%lld",ans);
}

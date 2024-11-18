#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
struct node
{
	ll t,p;
	bool operator<(node b){return t==b.t?p<b.p:t>b.t;}
}tp[200010];
priority_queue<ll>q;
int main()
{
	ll n=read(),L=read(),ans=0;
	for(int i=1;i<=n;++i)tp[i]={read(),read()};
	sort(tp+1,tp+n+1);
	for(int i=1;i<=n;++i)
	{
		q.push(-tp[i].p);
		if(tp[i].p>-q.top())
		{
			ans+=tp[i].p+q.top();
			q.pop();
			q.push(-tp[i].p);
		}
	}
	write(ans);
	puts("");
	return 0;
}

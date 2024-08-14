#include<bits/stdc++.h>
#define ll long long
#define M 100010
#define lowbit(x) ((x)&(-x))
const ll p=1000000007;
using namespace std;
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
inline ll HOU(ll x)
{
	return (x*(x+1)/2)%p;
}
ll n,ans,h[M],w[M];
stack<ll>stk1,stk2;
int main()
{
	//freopen("celeste.in","r",stdin);
	//freopen("celeste.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)h[i]=read();
	for(int i=1;i<=n;++i)w[i]=read();
	stk1.push(-998244353);
	for(int i=1;i<=n+1;++i)
	{
		ll sumw=0;
		while(h[i]<=stk1.top())
		{
			ll top1=stk1.top(),top2=stk2.top();
			stk1.pop(),stk2.pop();
			(sumw+=top2)%=p;
			(ans+=(HOU(top1)-HOU(max(h[i],stk1.top()))+p)%p*HOU(sumw)%p)%=p;
		}
		stk1.push(h[i]),stk2.push((w[i]+sumw)%p);
	}
	write(ans);
	return 0;
}

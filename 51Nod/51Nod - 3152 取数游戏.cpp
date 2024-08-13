#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rnd(time(0));
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
ll a[11010100],Prime[11451411],pm[11451411],mi[11451411],dg[11451411],Primetot,n,k,ans,idx,tot;
bool isPrime[11451411];
void Eulerphi(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!isPrime[i])Prime[++Primetot]=i;
		for(ll j=1;j<=Primetot&&i*Prime[j]<=n;++j)
		{
			isPrime[Prime[j]*i]=1;
			if(!(i%Prime[j]))break;
		}
	}
}
void dfs(ll pos,ll val)
{
    if(pos==tot+1)
	{
		dg[++idx]=val;
		return;
	}
    dfs(pos+1,val);
    for(ll i=1;i<=mi[pos];++i)val*=pm[pos],dfs(pos+1,val);
}
bool judge(ll x)
{
	ll cnt=0;
	for(ll i=1;i<=n;++i)if(!(a[i]%x))++cnt;
	return (cnt>=k);
}
unordered_map<ll,ll>syh;
void solve(ll x)
{
    tot=idx=0;
    for(ll i=1;Prime[i]<=x/Prime[i];++i)
        if(x%Prime[i]==0)
		{
            pm[++tot]=Prime[i];mi[tot]=0;
            while(x%Prime[i]==0)x/=Prime[i],++mi[tot];
        }
    if(x>1)pm[++tot]=x,mi[tot]=1;
    dfs(1,1);
    for(ll i=1;i<=idx;++i)
	{
        if(syh[dg[i]])continue;
        syh[dg[i]]=1;
        if(judge(dg[i]))ans=max(ans,dg[i]);
    }
}
int main()
{
	//freopen("choice.in","r",stdin);
	//freopen("choice.out","w",stdout);
	ll T=read();
	Eulerphi(11000000);
	while(T--)
	{
		n=read();k=(n+1)>>1;
		for(ll i=1;i<=n;++i)a[i]=read();
		ans=1;
		unordered_map<ll,ll>mp;
		syh.clear();
		for(int t=1;t<=10;++t)
		{
			ll id=rnd()%n+1;
			if(mp[a[id]])continue;
			mp[a[id]]=1;
			solve(a[rnd()%n+1]);
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

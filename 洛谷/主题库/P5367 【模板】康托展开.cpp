#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&(-x)) 
using namespace std;
const int mod=998244353;
inline int read()
{
    int x=0,f=1;
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
inline void write(int x)
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
int ans,n,tr[4001000],frac[4000100];
inline void add(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))(tr[i]+=v)%=mod;
}
inline int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))(res+=tr[i])%=mod;
	return res;
}
signed main()
{
	n=read();
	frac[0]=1;
	for(int i=1;i<=n;++i)
	{
		tr[i]=lowbit(i); 
		frac[i]=(frac[i-1]*i)%mod;
	}
	for(int i=1;i<=n;++i)
	{
		int x=read();
		add(x,-1);
		ans=(ans+query(x)*frac[n-i]%mod)%mod;
	}
	write(ans+1);
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
inline int read()
{
    register int x=0,f=1;
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
inline int lowbit(int x)
{
	return ((x)&(-x));
}
int n,ans,tr[100010],num[100010],lsh[100010],f[100010],lst[100010];
bool vis[100010];
inline void add(int x,int v)
{
	for(register int i=x;i<=n;i+=lowbit(i))(tr[i]+=v)%mod;
}
inline int query(int x)
{
	register int res=0;
	for(register int i=x;i;i-=lowbit(i))res+=tr[i];
	return res%mod;
}
signed main()
{
	n=read();
    for(register int i=0;i<n;++i)num[i]=lsh[i]=read();
    sort(lsh,lsh+n);
	int len=unique(lsh,lsh+n)-lsh;
    for(register int i=0;i<n;++i)num[i]=lower_bound(lsh,lsh+len,num[i])-lsh+1;
    for(register int i=0;i<n;++i)
	{
        f[i]=query(num[i]-1)%mod;
        if(vis[num[i]])add(num[i],(f[i]-lst[num[i]]+mod)%mod);
        else add(num[i],f[i]+1),vis[num[i]]=1;
        (ans+=(f[i]-lst[num[i]]+mod)%mod)%=mod;
        lst[num[i]]=f[i];
    }
    write(ans);
    return 0;
}

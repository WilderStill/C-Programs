#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
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
int n,k,tl,tr,num[100010],cnt[100010];
ll sum,f[100010][21];
inline void add(int x)
{
	sum+=cnt[num[x]]; 
	++cnt[num[x]];
}
inline void del(int x)
{
	--cnt[num[x]];
	sum-=cnt[num[x]]; 
}
inline void solve(int dep,int l,int r,int posl,int posr)
{
	int mid=(l+r)>>1,pos;
	ll res=INF;
	for(int i=max(1,posl);i<=min(mid,posr);++i)
	{
		int pl=i,pr=mid;
		while(tl>pl)add(--tl);
		while(tr<pr)add(++tr);
		while(tl<pl)del(tl++);
		while(tr>pr)del(tr--);
		ll val=f[i-1][dep-1]+sum;
		if(val<res)res=val,pos=i;
	}
	f[mid][dep]=res;
	if(l==r)return;
	solve(dep,l,mid,posl,pos);
	solve(dep,mid+1,r,pos,posr);
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;++i)num[i]=read(),f[i][0]=INF;
	f[0][0]=0;
	cnt[0]=1;
	for(int i=1;i<=k;++i)solve(i,1,n,1,n);
	write(f[n][k]);
    return 0;
}


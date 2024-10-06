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
int n,k,X,tl=1,tr,num[200010],cnt[2000010];
ll sum,f[200010][21];
inline void add(int x)
{
	sum+=cnt[num[x]^X]; 
	++cnt[num[x]];
}
inline void del(int x)
{
	--cnt[num[x]];
	sum-=cnt[num[x]^X]; 
}
inline ll query(int pl,int pr)
{
	while(tl>pl)add(--tl);
	while(tr<pr)add(++tr);
	while(tr>pr)del(tr--);
	while(tl<pl)del(tl++);
	return sum;
}
inline void solve(int dep,int l,int r,int posl,int posr)
{
	if(l>r)return;
	int mid=(l+r)>>1,pos=posl;	
	f[mid][dep]=f[pos][dep-1]+query(pos,mid);
	for(int i=posl+1;i<=min(mid,posr);++i)
	{
		ll val=f[i][dep-1]+query(i,mid);
		if(val<f[mid][dep])f[mid][dep]=val,pos=i;
	}
	solve(dep,l,mid-1,posl,pos);
	solve(dep,mid+1,r,pos,posr);
}
int main()
{
	n=read(),k=read(),X=read();
	for(int i=1;i<=n;++i)num[i]=read()^num[i-1],f[i][0]=INF;
	f[0][0]=0;
	for(int i=1;i<=k;++i)solve(i,0,n,0,n);
	write(f[n][k]);
    return 0;
}

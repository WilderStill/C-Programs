#include<bits/stdc++.h>
#define p 998244353
#define ll long long
#define M 11451411
using namespace std;
int n,m,tot,a[M],zero[M];
inline ll read()
{
	ll x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')fg=-1; 
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=((x<<1)+(x<<3)+(ch^48))%p,ch=getchar();
	return fg*x;
}
inline bool check(ll x)
{
    ll sum=0;
    for(int i=n;i>=1;--i)sum=((a[i]+sum)*x)%p;
    sum=(sum+a[0])%p;
    return !sum;
}
int main()
{
    n=read(),m=read();
    for(int i=0;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)if(check(i))zero[++tot]=i;
	printf("%d\n",tot);
    if(tot)for(int i=1;i<=tot;++i)printf("%d\n",zero[i]);
    return 0;
}


#include<bits/stdc++.h>
#define ll long long
#define M 114
using namespace std;
ll T,n,t,m,f[M][M];
inline ll read()
{
    register ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		scanf("%lld%lld%lld",&n,&t,&m);
		for(ll i=1,tmp;i<=n;++i)
		{
			tmp=read();
			for(ll j=m;j>=1;--j)
				for(ll k=t;k>=tmp;--k)
					f[j][k]=max(f[j][k],max(f[j-1][t]+1,f[j][k-tmp]+1));
		}
		printf("%lld\n",f[m][t]);
		if(T)puts("");
	}
	return 0;
}

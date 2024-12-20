#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[50010];
struct ld
{
	int w,l;
	bool operator<(const ld&b)const
	{
		return l^b.l?l>b.l:w>b.w;
	}
}sp[50010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&sp[i].w,&sp[i].l),sp[i].w=abs(sp[i].w),sp[i].l=abs(sp[i].l);
	sort(sp+1,sp+n+1);
	int m=1;
	for(int i=1;i<=n;++i)if(sp[i].w>sp[m].w)sp[++m]=sp[i];
	n=m;
	for(int i=1;i<=n;++i)
	{
		f[i]=1e18;
		for(int j=0;j<i;++j)
			if(f[i]>f[j]+1ll*sp[i].w*sp[j+1].l)
				f[i]=f[j]+1ll*sp[i].w*sp[j+1].l;
	}
	printf("%lld",f[n]<<2);
	return 0;
} 

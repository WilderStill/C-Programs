#include<bits/stdc++.h>
#define M 114514 
#define ll long long
using namespace std;
int n, lens=1,lenm=1,lena=1;
int sum[M]={0,1},maxn[M]={0,1},ans[M];
struct node
{
	ll l, r;
	bool operator < (const node x) const 
	{
		return l*r< x.l*x.r;
	}
}cn[M];
void mul(ll x)
{
	int tmp=0;
	for(int i=1;i<=lens;i++)sum[i]*=x;
	for(int i=1;i<=lens;i++)
	{
		tmp+=sum[i];
		sum[i]=tmp %10;
		tmp/=10;
	}
	while(tmp!=0)
	{
		lens++;
		sum[lens]=tmp%10;
		tmp/=10;
	}
}
void cut(ll x)
{
	memset(ans,0,sizeof(ans));
	lena=lens;
	int tmp=0;
	for(int i=lena;i>=1;i--)
	{
		tmp*=10;
		tmp+=sum[i];
		if(tmp>=x)
		{
			ans[i]=tmp/x;
			tmp%=x;
		}
	}
	while(ans[lena]==0)
	{
		if(lena==1) break;
		lena--;
	}
}
void max()
{
	if(lena>lenm)
	{
		for(int i=1;i<=lena;i++)maxn[i]=ans[i];
		lenm=lena;
	}
	else if(lena==lenm)
	{
		for(int i=lena;i>=1;i--)
			if(maxn[i]<ans[i])
			{
				for(int j=1;j<=lena;j++)
					maxn[j]=ans[j];
				lenm=lena;
				break;
			}
	}
}
int main()
{
	scanf("%d%lld%lld",&n,&cn[0].l,&cn[0].r);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&cn[i].l,&cn[i].r);
	sort(cn+1,cn+n+1);
	for(int i=1;i<=n;i++)
	{
		mul(cn[i-1].l);
		cut(cn[i].r);
		max();
	}
	for(int i=lenm;i>=1;i--)printf("%d",maxn[i]);
	return 0; 
}

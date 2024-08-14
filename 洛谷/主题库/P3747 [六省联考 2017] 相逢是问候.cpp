#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
#define M 50010
#define ll long long
using namespace std;
ll n,p,m,c,ptot,num[M],phi[30],_gcd[30],f[M][30][30],s[10005][30][2];
bool b[M][30][2],syh[M][30][30];
ll get_phi(ll x)
{
	ll res=x;
	for(ll i=2;i*i<=x;++i)
	{
		if(x%i)continue;
		res=res*(i-1)/i;
		while(!(x%i))x/=i;
	}
	if(x>1)res=res*(x-1)/x;
	return res;
}
void init()
{
	ll x=p;
	phi[0]=p;
	while(x!=1)
	{
		x=get_phi(x);
		phi[++ptot]=x;
	}
	phi[++ptot]=1;
	for(int i=0;i<=ptot;++i)_gcd[i]=__gcd(c,phi[i]);
	for(int j=0;j<=ptot;++j)
	{
		s[0][j][0]=1;
		for(int i=1;i<=10000;++i)
		{
			s[i][j][0]=s[i-1][j][0]*c;
			if(s[i][j][0]>=phi[j])
			{
				s[i][j][0]%=phi[j];
				b[i][j][0]=1;
			}
			b[i][j][0]|=b[i-1][j][0];
		}
	}
	for(int j=0;j<=ptot;++j)
	{
		s[0][j][1]=1;
		b[1][j][1]=b[10000][j][0];
		for(int i=1;i<=10000;++i)
		{
			s[i][j][1]=s[i-1][j][1]*s[10000][j][0];
			if(s[i][j][1]>=phi[j])
			{
				s[i][j][1]%=phi[j];
				b[i][j][1]=1;
			}
			b[i][j][1]|=b[i-1][j][1];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int k=0;k<=ptot;++k)
		{
			f[i][0][k]=num[i]%phi[k];
			if(num[i]>=phi[k])syh[i][0][k]=1;
		}
		for(int j=1;j<=ptot;++j)
		{
			f[i][j][ptot]=0;
			for(int k=0;k<ptot;++k)
			{
				f[i][j][k]=s[f[i][j-1][k+1]/10000][k][1]*s[f[i][j-1][k+1]%10000][k][0];
				syh[i][j][k]=(b[f[i][j-1][k+1]/10000][k][1]||b[f[i][j-1][k+1]%10000][k][0]);
				if(f[i][j][k]>=phi[k])
				{
					f[i][j][k]%=phi[k];
					syh[i][j][k]=1;
				}
				if(_gcd[k]!=1&&syh[i][j-1][k+1])
				{
					f[i][j][k]=f[i][j][k]*s[phi[k+1]/10000][k][1]%phi[k]*s[phi[k+1]%10000][k][0];
					if(f[i][j][k]>=phi[k])
					{
						f[i][j][k]%=phi[k];
						syh[i][j][k]=1;
					}
					syh[i][j][k]=(syh[i][j][k]||b[phi[k+1]/10000][k][1]||b[phi[k+1]%10000][k][0]);
				}
			}	
		}
	}
}
struct node
{
	ll v,minn;
}tree[M*4];
void pushup(ll rt)
{
	tree[rt].v=tree[lson].v+tree[rson].v;
	tree[rt].minn=min(tree[lson].minn,tree[rson].minn);
}
void build(ll rt,ll l,ll r)
{
	if(l==r)
	{
		tree[rt].v=num[l];
		tree[rt].minn=0;
		return;
	}
	ll mid=l+((r-l)>>1);
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}
void modify(ll rt,ll l,ll r,ll posl,ll posr)
{
	if(tree[rt].minn>=ptot)return;
	if(l>posr||r<posl)return;
	if(l==r)
	{
		++tree[rt].minn;
		tree[rt].v=f[l][tree[rt].minn][0]%p;
		return;
	}
	ll mid=l+((r-l)>>1);
	if(tree[lson].minn<ptot)modify(lson,l,mid,posl,posr);
	if(tree[rson].minn<ptot)modify(rson,mid+1,r,posl,posr);
	pushup(rt);
}
ll query(ll rt,ll l,ll r,ll posl,ll posr)
{
	if(l>posr||r<posl)return 0;
	if(l>=posl&&r<=posr)return tree[rt].v%p;
	ll mid=l+((r-l)>>1);
	return (query(lson,l,mid,posl,posr)+query(rson,mid+1,r,posl,posr))%p;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&p,&c);
    for(ll i=1;i<=n;i++)scanf("%lld",&num[i]);
	init();
	build(1,1,n);
	for(ll i=1,k,l,r;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&r);
		if(l>r)swap(l,r);
		if(!k)modify(1,1,n,l,r);
		else printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
}

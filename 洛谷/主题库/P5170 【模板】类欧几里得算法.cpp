#include <bits/stdc++.h>
#define ll long long
#define p2(x) (x)*(x)
#define P 998244353
#define i2 499122177
#define i6 166374059
using namespace std;
struct Euclid
{
	Euclid(){f=0,g=0,h=0;}
	ll f,g,h;
};
Euclid calc(ll n,ll a,ll b,ll c)
{
	ll m=(a*n+b)/c;
	Euclid res;
	if(a==0)
	{  // 迭代到最底层
		res.f=(b/c)*(n+1)%P;
		res.g=(b/c)*n%P*(n+1)%P*i2%P;
		res.h=p2(b/c)%P*(n+1)%P;
		return res;
	}
	if(a>=c||b>=c)
	{  // 取模
		res.f=n*(n+1)%P*i2%P*(a/c)%P+(b/c)*(n+1)%P;
		res.g=(a/c)*n%P*(n+1)%P*(n*2+1)%P*i6%P+(b/c)*n%P*(n+1)%P*i2%P;
		res.h=p2(a/c)%P*n%P*(n+1)%P*(n*2+1)%P*i6%P+p2(b/c)%P*(n+1)%P+(a/c)*(b/c)%P*n%P*(n+1)%P;
		res.f%=P,res.g%=P,res.h%=P;
		Euclid tmp=calc(n,a%c,b%c,c);  // 迭代
		res.h+=tmp.h+2*(b/c)%P*tmp.f%P+2*(a/c)%P*tmp.g%P;
		res.g+=tmp.g,res.f+=tmp.f;
		res.f%=P,res.g%=P,res.h%=P;
		return res;
	}
	Euclid tmp=calc(m-1,c,c-b-1,a);
	res.f=n*m%P-tmp.f,res.f=(res.f%P+P)%P;
	res.g=m*n%P*(n+1)%P-tmp.h-tmp.f,res.g=(res.g*i2%P+P)%P;
	res.h=n*m%P*(m+1)%P-2*tmp.g-2*tmp.f-res.f;
	res.h=(res.h%P+P)%P;	
	return res;
}
int main()
{
	ll t,n,a,b,c;
	scanf("%lld",&t);
	for(ll i=1;i<=t;i++)
	{
		scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
		Euclid ans=calc(n,a,b,c);
		printf("%lld %lld %lld\n",ans.f,ans.h,ans.g);
	}
	return 0;
}

#include<bits/stdc++.h>
#define M 214
#define ll long long
using namespace std;
ll n,m,p,c[M*10][M*10];
struct Matrix
{
    ll a[M][M];
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        memset(res.a,0,sizeof(res.a));
        for(ll i=0;i<=m+1;i++)
			for(ll k=0;k<=m+1;k++)
				if(a[i][k])
            		for(ll j=0;j<=m+1;j++)
                		res.a[i][j]=((res.a[i][j]+a[i][k]*b.a[k][j])+p)%p;
        return res;
	}
}ans,t;
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%p;
		x=x*x%p;
		y/=2;
	}
	return res;
}
Matrix qpow(Matrix x,ll y)
{
	Matrix res=x;
	y--;
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x;
		y/=2;
	}
	return res;
}
ll cal(ll x,ll y)
{
	if(y==1)return x;
	if(y&1)return (cal(x,y-1)+1)*x%p;
	return cal(x,y/2)*(1+qpow(x,y/2))%p;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&p);
	ll k=(m*(m-3)+3)%p;
	if(m<=200)
	{
		for(ll i=0;i<=m;i++)
			for(ll j=0;j<=i;j++)
			{
				c[i][j]=j?(c[i-1][j-1]+c[i-1][j])%p:1;
				t.a[i][j]=k*c[i][j]%p;
			}
		for(ll i=0;i<=m;i++)ans.a[i][0]=1;
		t.a[m+1][m+1]=t.a[m+1][m]=1;
		ans=qpow(t,n-1)*ans;
		printf("%lld",((ans.a[m+1][0]+ans.a[m][0])%p*qpow(2,m)%p*m%p*(m-1)%p+p)%p);
	}
	else
	{
		ll res=0;
		for(ll i=1;i<=p;i++)res=(res+qpow(i,m)%p*qpow(k,i-1)%p+p)%p;
		res=res*(cal(qpow(k,p),n/p-1)+1)%p;
		for(ll i=n-n%p+1;i<=n;i++)res=(res+qpow(i,m)%p*qpow(k,i-1)%p+p)%p;
		printf("%lld",(res%p*qpow(2,m)%p*m%p*(m-1)%p+p)%p);
	}
	return 0;
}
//啊，WA是吧，那我就全加上%p，哈哈哈（doge 

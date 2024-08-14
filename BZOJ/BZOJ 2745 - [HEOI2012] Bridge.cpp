#include<bits/stdc++.h>
#define M 205
#define ll long long
using namespace std;
ll n,m,p,c[M*10][M*10];
struct Matrix
{
    ll a[M][M];
    inline Matrix():a{0}{}
    inline operator auto(){return a;}
    inline operator auto()const{return a;}
    inline Matrix operator*(const Matrix &b) const {
        Matrix res;
        for(int i=0;i<=m+1;++i)
			for(int k=0;k<=m+1;++k)
				if(a[i][k])
            		for(int j=0;j<=m+1;++j)
                		res[i][j]=(res[i][j]+a[i][k]*b[k][j])%p;
        return res;
	}
}ans,t;
inline ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res;
}
inline Matrix qpow(Matrix res,Matrix x,ll y)
{
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
inline ll cal(ll x,ll y)
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
		c[0][0]=1;
		for(int i=1;i<=m;c[i][0]=1,++i)
			for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
		for(int i=0;i<=m;++i)ans.a[0][i]=1;
		t.a[m+1][m+1]=t.a[m][m+1]=1;
		for(int i=0;i<=m;++i)
			for(int j=0;j<=m;++j)t.a[j][i]=c[i][j]*k%p;
		printf("%lld",((m*m-m)%p+p)%p*qpow(2,m)%p*(qpow(ans,t,n)[0][m+1])%p);
	}
	else
	{
		ll res=0;
		for(int i=1;i<=p;++i)res=(res+qpow(i,m)%p*qpow(k,i-1)%p+p)%p;
		res=res*(cal(qpow(k,p),n/p-1)+1)%p;
		for(int i=n-n%p+1;i<=n;++i)res=(res+qpow(i,m)%p*qpow(k,i-1)%p+p)%p;
		printf("%lld",(res%p*qpow(2,m)%p*m%p*(m-1)%p+p)%p);
	}
	return 0;
}


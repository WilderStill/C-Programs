#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p,a,c,x0,n,g;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
ll mul(ll x,ll y)
{
	ll res=0;
	while(y)
	{
		if(y&1)res=(res+x)%p;
		x=(x+x)%p;
		y>>=1;
	}
	return res%p;
}
struct Matrix
{
    ll a[3][3];
    Matrix(){memset(a,0,sizeof a);}
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                for(int k=1;k<=2;k++)
                    res.a[i][j]=(res.a[i][j]+mul(a[i][k],b.a[k][j])+p)%p;
        return res;
    }
}ans,base;
void init()
{
    base.a[1][1]=a;
	base.a[1][2]=1;
	base.a[2][2]=1;
    ans.a[1][1]=x0;
	ans.a[2][1]=c;
}
Matrix qpow(Matrix x,ll y)
{
	Matrix res;
	for(int i=1;i<=2;++i)res.a[i][i]=1;
    while(y)
    {
        if(y&1)res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}
int main()
{
	p=read(),a=read(),c=read(),x0=read(),n=read(),g=read();
	if(!n)
	{
		printf("%lld",x0);
		return 0;
	}
    init();
    ans=qpow(base,n)*ans;
    printf("%lld",ans.a[1][1]%g);
}

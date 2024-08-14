#include<bits/stdc++.h>
#define p 1000000007
#define ll long long
using namespace std;
ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
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
                    res.a[i][j]=((res.a[i][j]+a[i][k]*b.a[k][j])%p+p)%p;
        return res;
    }
}ans,base;
void init()
{
    base.a[1][1]=1;
	base.a[1][2]=1;
	base.a[2][1]=1;
    ans.a[1][1]=1;
	ans.a[1][2]=1;
}
void qpow(ll x)
{
    while(x)
    {
        if(x&1)ans=ans*base;
        base=base*base;
        x>>=1;
    }
}
int main()
{
	ll n=read();
    if(n<=2)
    {
    	printf("1");
    	return 0;
	}
    init();
    qpow(n-2);
    printf("%lld",ans.a[1][1]%p);
}

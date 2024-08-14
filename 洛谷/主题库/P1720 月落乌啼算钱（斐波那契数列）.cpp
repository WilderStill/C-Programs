#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Matrix
{
    ll a[3][3];
    Matrix(){memset(a,0,sizeof a);}
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                for(int k=1;k<=2;k++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]);
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
	ll n;
	scanf("%lld",&n);
	if(n==0)
	{
		printf("0.00");
		return 0;
	}
    if(n<=2)
    {
    	printf("1.00");
    	return 0;
	}
    init();
    qpow(n-2);
    printf("%lld.00",ans.a[1][1]);
    return 0;
}

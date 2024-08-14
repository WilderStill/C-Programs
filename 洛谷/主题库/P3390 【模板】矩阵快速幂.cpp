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
    ll a[114][114],n;
    Matrix(){}
    void clear(){memset(a,0,sizeof a);}
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        res.n=n;
		res.clear();
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]%p)%p;
        return res;
    }
}ans,base;
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
	ll k;
	base.clear();ans.clear();
	scanf("%lld %lld",&ans.n,&k);base.n=ans.n;
	for(int i=1;i<=ans.n;i++)
        for(int j=1;j<=ans.n;j++)
        	scanf("%lld",&base.a[i][j]);
    for(int i=1;i<=base.n;i++)ans.a[i][i]=1;
    qpow(k);
    for(int i=1;i<=ans.n;i++)
    {
    	for(int j=1;j<=ans.n;j++)
        	printf("%lld ",ans.a[i][j]);
        puts("");
	}
}

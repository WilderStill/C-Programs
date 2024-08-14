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
    ll a[4][4];
    Matrix(){}
    void clear(){memset(a,0,sizeof a);}
    Matrix operator*(const Matrix &b) const {
        Matrix res;res.clear();
        for(int k=1;k<=3;k++)
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]%p)%p;
        return res;
    }
}ans,base;
void init()
{
	base.clear();
    base.a[1][1]=base.a[2][1]=base.a[1][3]=base.a[3][2]=1;
	ans.clear();
    ans.a[1][1]=ans.a[2][2]=ans.a[3][3]=1;
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
	ll n,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n<=3)
	    {
	    	printf("1\n");
	    	continue;
		}
	    init();
	    qpow(n);
	    printf("%lld\n",ans.a[2][1]);
	}
    
}

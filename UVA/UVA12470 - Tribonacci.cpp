#include<bits/stdc++.h>
#define ll long long
#define p 1000000009
using namespace std;
struct Matrix
{
    ll a[4][4];
    void clear(){memset(a,0,sizeof a);}
    friend Matrix operator *(Matrix x,Matrix y)
	{
        Matrix res;
        res.clear();
        for(ll i=1;i<=3;i++)
            for(ll j=1;j<=3;j++)
                for(ll k=1;k<=3;k++)
                    res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%p;
        return res;
    }
    Matrix(ll a1=0,ll a2=0,ll a3=0,ll b1=0,ll b2=0,ll b3=0,ll c1=0,ll c2=0,ll c3=0)
    {
        a[1][1]=a1;a[1][2]=a2;a[1][3]=a3;a[2][1]=b1;a[2][2]=b2;a[2][3]=b3;a[3][1]=c1;a[3][2]=c2;a[3][3]=c3;
    }
};
const Matrix res(1,0,0,0,1,0,0,0,1);
Matrix qpow(Matrix x,ll n)
{
    if(n==0)return res;
    Matrix t=qpow(x,n/2);
    t=t*t;
    if(n&1)t=t*x;
    return t;
} 
int main()
{
	ll n;
	while(scanf("%lld",&n))
	{
		if(n==0)return 0;
		if(n==1){printf("0\n");continue;}
	    if(n==2){printf("1\n");continue;}
		if(n==3){printf("2\n");continue;}
	    Matrix ans(2,1,0),base(1,1,0,1,0,1,1,0,0);
	    Matrix now=ans*qpow(base,n-3);
	    printf("%lld\n",now.a[1][1]);
	}
}

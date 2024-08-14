#include<bits/stdc++.h>
#define ll __int128
using namespace std;
ll p=1000000007;
ll read()
{
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=((x<<1)+(x<<3)+(ch^48))%(p-1),ch=getchar();
	return x%p;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
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
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%p;
        return res;
    }
}ans,base;
void init()
{
    base.a[1][1]=2;
	base.a[1][2]=1;
	base.a[2][1]=1;
    ans.a[1][1]=2;
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
	init();
	if(n==0)printf("0");
	else if(n==1)printf("1");
	else if(n==2)printf("2");
	else 
	{
		qpow(n-2);
		write(ans.a[1][1]%p);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long ll;
const int M=4000010;
const ld pi=acos(-1.0);
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
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
complex<ld>f[M],g[M];
inline void FFT(complex<ld>*num,ll n)
{
	if(n==1)return;
	n=n>>1;
	complex<ld>a0[n+1],a1[n+1];
	for(int i=0;i<n;++i)
		a0[i]=num[i<<1],a1[i]=num[i<<1|1];
	FFT(a0,n);
	FFT(a1,n);
	auto wk=complex<ld>(cos(1.0*pi/n),sin(1.0*pi/n)),wi=complex<ld>(1.0,0.0);
	for(int i=0;i<n;++i)
	{
		num[i]=a0[i]+wi*a1[i];
		num[i+n]=a0[i]-wi*a1[i];
		wi*=wk;
	}
}
inline void IFFT(complex<ld>*num,ll n)
{
	if(n==1)return;
	n=n>>1;
	complex<ld>a0[n+1],a1[n+1];
	for(int i=0;i<n;++i)
		a0[i]=num[i<<1],a1[i]=num[i<<1|1];
	IFFT(a0,n);
	IFFT(a1,n);
	auto wk=complex<ld>(cos(1.0*pi/n),-sin(1.0*pi/n)),wi=complex<ld>(1.0,0.0);
	for(int i=0;i<n;++i)
	{
		num[i]=a0[i]+wi*a1[i];
		num[i+n]=a0[i]-wi*a1[i];
		wi*=wk;
	}
}
int main()
{
    ll n=read(),m=read(),len=1;
    for(int i=0;i<=n;++i)f[i]=read();
    for(int i=0;i<=m;++i)g[i]=read();
    while(len<=n+m)len<<=1;
    FFT(f,len);
    FFT(g,len);
    for(int i=0;i<=len;++i)f[i]=f[i]*g[i];
    IFFT(f,len);
    for(int i=0;i<=n+m;++i)write((ll)round(f[i].real()/len)),putchar(' ');
    return 0;
}

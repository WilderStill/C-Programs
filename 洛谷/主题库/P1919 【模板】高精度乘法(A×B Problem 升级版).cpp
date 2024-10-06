#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const int M=4000010;
const ld pi=acos(-1.0);
inline int read()
{
    int x=0,f=1;
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
inline void write(int x)
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
int len,l,r[M],ans[M];
inline void FFT(complex<ld>*num,int n)
{
	for(int i=0;i<n;++i)if(i<r[i])swap(num[i],num[r[i]]);
	for(int ps=1;ps<n;ps<<=1)
    {
        auto wk=complex<ld>(cos(pi/ps),sin(pi/ps));
        for(int len=ps<<1,i=0;i<n;i+=len)
        {
        	auto wi=complex<ld>(1.0,0.0);
            for(int j=0;j<ps;++j)
            {
                auto tf=num[i+j],tp=wi*num[i+ps+j];
                num[i+j]=tf+tp;
                num[i+ps+j]=tf-tp;
				wi*=wk;
            }
        }
    }
}
inline void IFFT(complex<ld>*num,int n)
{
	for(int i=0;i<n;++i)if(i<r[i])swap(num[i],num[r[i]]);
	for(int ps=1;ps<n;ps<<=1)
    {
        auto wk=complex<ld>(cos(pi/ps),-sin(pi/ps));
        for(int len=ps<<1,i=0;i<n;i+=len)
        {
        	auto wi=complex<ld>(1.0,0.0);
            for(int j=0;j<ps;++j)
            {
                auto tp=wi*num[i+ps+j],tf=num[i+j];
                num[i+j]=tf+tp;
                num[i+ps+j]=tf-tp;
				wi*=wk;
            }
        }
    }
}
char s1[M],s2[M];
int main()
{
	scanf("%s%s",s1,s2);
	int n=strlen(s1),m=strlen(s2);
    for(int i=0;i<n;++i)f[i]=s1[n-i-1]-'0';
	for(int i=0;i<m;++i)g[i]=s2[m-i-1]-'0';
	len=1;
	while(len<=n+m)len<<=1,++l;
    for(int i=0;i<len;++i)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    FFT(f,len);
    FFT(g,len);
    for(int i=0;i<=len;++i)f[i]=f[i]*g[i];
    IFFT(f,len);
    for(int i=0;i<len;++i)
    {
		ans[i]+=(int)round(f[i].real()/len);
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	while(!ans[len]&&~len)--len;
	if(~len)for(int i=len;~i;--i)write(ans[i]);
	else puts("0");
	return 0;
}


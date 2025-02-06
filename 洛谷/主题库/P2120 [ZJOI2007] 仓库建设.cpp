#include<bits/stdc++.h>
#define int long long
using namespace std;
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
        x=(x<<1)+(x<<3)+(ch&15);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
typedef long double ld;
const int M=1e6+4;
int n,hd,tl,c[M],x[M],p[M],sp[M],sf[M],f[M],q[M];
inline ld X(int i){return sp[i];}
inline ld Y(int i){return f[i]+sf[i];}
inline ld K(int i,int j){return X(j)-X(i)?(Y(j)-Y(i))/(X(j)-X(i)):(Y(j)>=Y(i)?2e18:-2e18);}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        x[i]=read(),p[i]=read(),c[i]=read();
        sp[i]=sp[i-1]+p[i];
        sf[i]=sf[i-1]+p[i]*x[i];
    }
    q[hd=tl=1]=0;
    for(int i=1;i<=n;++i)
    {
        while(hd<tl&&K(q[hd],q[hd+1])<=x[i])++hd;
        f[i]=f[q[hd]]+x[i]*(sp[i]-sp[q[hd]])-(sf[i]-sf[q[hd]])+c[i];
        while(hd<tl&&K(q[tl-1],q[tl])>=K(q[tl-1],i))--tl;
        q[++tl]=i;
    }
    int i=n;
	while(i&&!p[i])--i;
    for(;i<=n-1;++i)f[n]=min(f[n],f[i]);
    write(f[n]);
    return 0;
} 

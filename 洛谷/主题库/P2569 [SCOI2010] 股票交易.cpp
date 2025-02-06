#include<bits/stdc++.h>
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
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=2e3+4,INF=0x3f3f3f3f;
int n,m,w,hd,tl,dg,q[M],f[M][M];
int main()
{
    n=read(),m=read(),w=read();
	memset(f,-INF,sizeof f);
	f[0][0]=0;
    for(int i=1;i<=n;++i)
    {
    	int ap=read(),bp=read(),as=read(),bs=read();
    	dg=as;
    	for(int j=0;j<=dg;++j)f[i][j]=-ap*j;
    	for(int j=0;j<=m;++j)f[i][j]=max({f[i][j],f[i-1][j]});
    	if(i>w)
    	{
	        hd=1,tl=0;
	        for(int j=0;j<=m;++j)
	        {
	            while(hd<=tl&&as+q[hd]<j)++hd;
	            if(hd<=tl)f[i][j]=max(f[i][j],f[i-w-1][q[hd]]+(q[hd]-j)*ap);
	            while(hd<=tl&&f[i-w-1][q[tl]]+(q[tl]-j)*ap<=f[i-w-1][j])--tl;
	            q[++tl]=j;
			}
	        hd=1,tl=0;
	        for(int j=m;~j;--j)
	        {
	            while(hd<=tl&&bs+j<q[hd])++hd;
	            if(hd<=tl)f[i][j]=max(f[i][j],f[i-w-1][q[hd]]+(q[hd]-j)*bp);
	            while(hd<=tl&&f[i-w-1][q[tl]]+(q[tl]-j)*bp<=f[i-w-1][j])--tl;
	            q[++tl]=j;
			}
		}
    }
    int ans=-INF;
    for(int i=0;i<=dg;++i)ans=max(ans,f[n][i]);
	write(ans);
    return 0;
}

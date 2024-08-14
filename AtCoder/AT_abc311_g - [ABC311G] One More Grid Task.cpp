#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
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
inline void write(long long x)
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
long long n,m,val[310][310],sum[310][310],ans=0,lft[301],rgt[310],stk[310],minn[310];
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			val[i][j]=read(),sum[i][j]=val[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)minn[j]=val[i][j];
		for(int j=i;j<=n;++j)
		{
			for(int k=1;k<=m;++k)minn[k]=min(minn[k],val[j][k]);
			int top=0;
			for(int k=1;k<=m;++k)
			{
				while(top&&minn[stk[top]]>minn[k])--top;
				lft[k]=(top?stk[top]+1:1);
				stk[++top]=k;
			}
			top=0;
			for(int k=m;k;--k)
			{
				while(top&&minn[stk[top]]>=minn[k])--top;
				rgt[k]=(top?stk[top]-1:m);
				stk[++top]=k;
			}
			for(int k=1;k<=m;++k)
				ans=max(ans,minn[k]*(sum[j][rgt[k]]-sum[j][lft[k]-1]-sum[i-1][rgt[k]]+sum[i-1][lft[k]-1]));	
		}
	}
	write(ans);
	return 0;
}

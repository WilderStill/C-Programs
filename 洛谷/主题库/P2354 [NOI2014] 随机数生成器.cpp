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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=5010;
int x[M*M],id[M*M],l[M],r[M];
signed main()
{
	x[0]=read();
	long long a=read(),b=read(),c=read(),d=read();
	int n=read(),m=read(),q=read(),mul=n*m;
	for(int i=1;i<=mul;++i)x[i]=(a*x[i-1]*x[i-1]+b*x[i-1]+c)%d,id[i]=i;
	for(int i=1;i<=mul;++i)swap(id[i],id[x[i]%i+1]);
	for(int i=1;i<=q;++i)
	{
		int u=read(),v=read();
		swap(id[u],id[v]);
	}
	for(int i=1;i<=mul;++i)x[id[i]]=i;
	for(int i=1;i<=n;++i)l[i]=1,r[i]=m;
	int cnt=0;
	for(int i=1;i<=mul;++i)
	{
		int dx=x[i]%m?x[i]/m+1:x[i]/m,dy=x[i]%m?x[i]%m:m;
		if(dy>=l[dx]&&dy<=r[dx])
		{
			write(i);
			putchar(' ');
			++cnt;
			for(int j=1;j<=n;++j)
			{
				if(j<dx)r[j]=min(r[j],dy);
				if(j>dx)l[j]=max(l[j],dy);
			}
			if(cnt==n+m-1)return 0;	
		}
	}
	return 0;
}

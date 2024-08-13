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
int ans,a[1<<19],fa[1<<19];
int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
signed main()
{
	int n=read(),m=read();
	while(n--)
	{
		int x=read();
		if(a[x])ans+=x;
		else a[x]=x;
	}
	for(int i=0;i<(1<<m);++i)fa[i]=i;
	for(int k=(1<<m)-1;k>=1;--k)
	{
		for(int i=1;i<(1<<m)&&!a[k];i<<=1)a[k]=a[k|i];
		int xfa=findfa(a[k]);
		for(int i=1;i<(1<<m);i<<=1)
			if(a[k|i])
			{
				int yfa=findfa(a[k|i]);
				if(xfa==yfa)continue;
				ans=ans+k;
				xfa=fa[xfa]=yfa;
			}
	}
	write(ans);
	return 0;
}

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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int ans[250010];
bool vis[250010];
int main()
{
	int n=read(),l=n*n;
	for(int i=1;i<=n;++i)
	{
		int x=read();
		ans[x]=i,vis[x]=1;
	}
	for(int i=1,j=1;i<=l;++i)
	{
		if(ans[i])
		{
			int cntp=ans[i]-1;
			while(cntp--)
			{
				while(ans[j])
				{
					if(ans[j]==ans[i])
					{
						puts("No");
						goto syh;
					}
					++j;
				}
				ans[j++]=ans[i];
			}
		}
	}
	for(int i=l,j=l;i;--i)
	{
		if(vis[i])
		{
			int cntp=n-ans[i];
			while(cntp--)
			{
				while(ans[j])
				{
					if(ans[j]==ans[i])
					{
						puts("No");
						goto syh;
					}
					--j;
				}
				ans[j--]=ans[i];
			}
		}
	}
	puts("Yes");;
	for(int i=1;i<=l;++i)write(ans[i]),putchar(' ');
	syh:;
	return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

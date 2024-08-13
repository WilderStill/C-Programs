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
int col[100010],n,k,vis[100010];
int main()
{
	memset(vis,-1,sizeof vis);
	n=read(),k=read();
	for(int syh=1;syh<=n;++syh)col[syh]=read();
	for(int syh=1;syh<=n;++syh)
	{
		if(!~vis[col[syh]])
		{
			int dg=max(col[syh]-k+1,0);
			for(int dugou=dg;dugou<=col[syh];++dugou)
			{
				if(!~vis[dugou]||col[syh]-vis[dugou]<k)
				{
					for(int lkz=dugou;lkz<=col[syh];++lkz)vis[lkz]=dugou;
					break;
				}
			}
		}
	}
	for(int syh=1;syh<=n;++syh)write(vis[col[syh]]),putchar(' ');
	return 0;
}


#include<bits/stdc++.h>
#define M 30010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
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
int fa[M],dis[M],syh[M];
int findfa(int x)
{
	if(x==fa[x])return x;
	int rt=fa[x];
	fa[x]=findfa(fa[x]);
	dis[x]+=dis[rt];
    syh[x]=syh[fa[x]];
	return fa[x];
}
int main()
{
	int T=read();
	for(int i=1;i<M;++i)fa[i]=i,syh[i]=1,dis[i]=0;
	while(T--)
	{
		char op[2];
		scanf("%s",&op);
		if(op[0]=='M')
		{
			int x=read(),y=read(),xfa=findfa(x),yfa=findfa(y);
			if(xfa^yfa)
			{
				fa[xfa]=yfa;
				dis[xfa]+=syh[yfa];
				syh[yfa]=(syh[xfa]+=syh[yfa]);
			}
		}
		else
		{
			int x=read(),xfa=findfa(x);
			write(dis[x]),puts("");
		}
	}
    return 0;
}

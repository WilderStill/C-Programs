#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
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
	putchar(x%10+'0');
	return;
}
mt19937 dg(time(0));
int hp[100010][2],val[100010],fa[100010];
bool vis[100010];
inline int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
inline int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(val[x]>val[y]||(val[x]==val[y]&&x>y))swap(x,y);
	if(dg()&1)swap(hp[x][0],hp[x][1]);
	hp[x][1]=merge(hp[x][1],y);
	fa[hp[x][1]]=x;
	return x;
}
inline void pop(int x)
{
	vis[x]=1;
	fa[hp[x][0]]=hp[x][0];
	fa[hp[x][1]]=hp[x][1];
	fa[x]=merge(hp[x][0],hp[x][1]);
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)val[i]=read(),fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read();
			int xfa=findfa(x),yfa=findfa(y);
			if(vis[x]||vis[y]||xfa==yfa)continue;
			fa[xfa]=fa[yfa]=merge(xfa,yfa);
		}
		else
		{
			int x=read();
			if(vis[x])puts("-1");
			else
			{
				int xfa=findfa(x);
				write(val[xfa]),puts("");
				pop(xfa);
			}
		}
	}
	return 0;
}

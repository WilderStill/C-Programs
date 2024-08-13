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
struct node
{
	int from,to,val;
	bool operator <(const node &dg)const{return val>dg.val;}
}edge[11451411];
int fa[11451411],d[11451411],ans;
int findfa(int x){return (fa[x]^x)?fa[x]=findfa(fa[x]):x;}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)fa[i]=i,d[i]=1;
	for(int i=1;i<=m;++i)
	{
		edge[i].from=read();
		edge[i].to=read();
		edge[i].val=read();
	}
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;++i)
	{
		int fromfa=findfa(edge[i].from),tofa=findfa(edge[i].to);
		if(fromfa!=tofa)
		{
			if(d[fromfa]||d[tofa])
			{
				fa[fromfa]=tofa;
				ans+=edge[i].val;
				d[tofa]=d[fromfa]&d[tofa];
			}
		}
		else
		{
			if(d[fromfa])
			{
				d[fromfa]=0;
				ans+=edge[i].val;
			}
		}
	}
	write(ans);
	return 0;
}


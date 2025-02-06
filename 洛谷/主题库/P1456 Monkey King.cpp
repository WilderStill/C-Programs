#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define M 100010
using namespace std;
using namespace __gnu_pbds;
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
struct node
{
    int val,pos;
    inline bool operator<(const node&b)const
	{
		if(val!=b.val)return val<b.val;
		return pos<b.pos;
	}
};
__gnu_pbds::priority_queue<node>hp[M];
int fa[M];
bool del[M];
inline int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
inline int merge(int x,int y)
{
	if(hp[x].size()>hp[y].size())
	{
		fa[y]=x;
		hp[x].join(hp[y]);
		return x;
	}
    else
	{
		fa[x]=y;
		hp[y].join(hp[x]);
		return y;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;++i)
			while(!hp[i].empty())
				hp[i].pop();
	    for(int i=1;i<=n;++i)
		{
			hp[i].push(node{read(),i});
			fa[i]=i;
		}
		int m=read();
	    for(int i=1;i<=m;++i)
		{
			int x=read(),y=read(),xfa=findfa(x),yfa=findfa(y);
	        if(xfa==yfa)
	        {
	        	puts("-1");
				continue;
			}
			node tx=hp[xfa].top();
			node ty=hp[yfa].top();
			hp[xfa].pop();
			hp[yfa].pop();
			hp[xfa].push((node){tx.val>>1,tx.pos});
			hp[yfa].push((node){ty.val>>1,ty.pos});
	        int fa=merge(xfa,yfa);
	        node top=hp[fa].top();
	        write(top.val),puts("");
	    }		
	}
    return 0;
}

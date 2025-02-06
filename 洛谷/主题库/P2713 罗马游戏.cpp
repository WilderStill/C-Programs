#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define M 1000010
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
		if(val!=b.val)return val>b.val;
		return pos>b.pos;
	}
};
__gnu_pbds::priority_queue<node>hp[M];
int fa[M];
bool del[M];
inline int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
inline void merge(int x,int y)
{
	if(hp[x].size()>hp[y].size())
	{
		fa[y]=x;
		hp[x].join(hp[y]);
	}
    else
	{
		fa[x]=y;
		hp[y].join(hp[x]);
	}
}
int main()
{
	int n=read();
    for(int i=1;i<=n;++i)
	{
		hp[i].push(node{read(),i});
		fa[i]=i;
	}
	int m=read();
    for(int i=1;i<=m;++i)
	{
        char op[2];
        scanf("%s",op);
        if(op[0]=='M')
		{
            int x=read(),y=read(),xfa=findfa(x),yfa=findfa(y);
            if(xfa==yfa||del[x]||del[y])continue;
            merge(xfa,yfa);
        }
		else
		{
            int x=read();
            if(del[x])
			{
				puts("0");
				continue;
			}
            int xfa=findfa(x);
            node top=hp[xfa].top();
			hp[xfa].pop();
            write(top.val),puts("");
            del[top.pos]=1;
        }
    }
    return 0;
}

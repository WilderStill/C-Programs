#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
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
		if(val^b.val)return val<b.val;
		return pos<b.pos;
	}
};
typedef __gnu_pbds::priority_queue<node> hp_node;
typedef __gnu_pbds::priority_queue<int> hp_num;
#define it point_iterator
hp_node hp[300010];
hp_num tp;
hp_node::it hop[300010];
hp_num::it top[300010];
int fa[300010],mk[300010],num[300010];
inline int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
inline void merge(int x,int y)
{
    if(hp[x].size()>hp[y].size())swap(x,y);
    for(auto i:hp[x])
	{
		int val=i.val,pos=i.pos;
		hop[pos]=hp[y].push((node){val+mk[x]-mk[y],pos});
		num[pos]=val+mk[x]-mk[y];
    }
    hp[x].clear(),tp.erase(top[x]);
	tp.modify(top[y],hp[y].top().val+mk[y]);
    fa[x]=y;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
    	num[i]=read();
		fa[i]=i;
		hop[i]=hp[i].push((node){num[i],i});
		top[i]=tp.push(num[i]);
	}
	int q=read();
    for(int i=1;i<=q;++i)
	{
        char op[3];
        scanf("%s",op);
        if(op[0]=='U')
        {
        	int x=read(),y=read();
        	int xfa=findfa(x),yfa=findfa(y);
        	if(xfa==yfa)continue;
        	merge(xfa,yfa);
		}
		if(op[0]=='A')
		{
			if(op[1]=='1')
			{
				int x=read(),v=read();
				int xfa=findfa(x);
				hp[xfa].modify(hop[x],(node){num[x]+v,x});
				num[x]+=v;
                tp.modify(top[xfa],hp[xfa].top().val+mk[xfa]);
			}
			if(op[1]=='2')
			{
				int x=read(),v=read();
				int xfa=findfa(x);
				mk[xfa]+=v;
                tp.modify(top[xfa],hp[xfa].top().val+mk[xfa]);
			}
			if(op[1]=='3')mk[0]+=read();
		}
		if(op[0]=='F')
		{
			if(op[1]=='1')
			{
				int x=read();
				int xfa=findfa(x);
				write(num[x]+mk[xfa]+mk[0]),puts("");
			}
			if(op[1]=='2')
			{
				int x=read();
				int xfa=findfa(x);
				write(hp[xfa].top().val+mk[xfa]+mk[0]),puts("");
			}
			if(op[1]=='3')write(tp.top()+mk[0]),puts("");
		}
    }
    return 0;
}

#include<bits/stdc++.h>
#define int long long
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
constexpr int M=2000010;
int tot,root,num[M];
struct node{int fa,dep,sum,son[2];}tr[M];
inline int newnode(int fa,int val){tr[++tot].fa=fa;tr[tot].sum=val;return tot;}
inline void update(int rt){tr[rt].dep=max(tr[tr[rt].son[0]].dep,tr[tr[rt].son[1]].dep)+1;tr[rt].sum=tr[tr[rt].son[0]].sum+tr[tr[rt].son[1]].sum+num[rt];return;}
inline bool getdir(int rt,int fa){return tr[fa].son[1]==rt;}
inline void connect(int rt,int fa,bool dir){tr[fa].son[dir]=rt;tr[rt].fa=fa;return;}
inline int findfa(int rt){while(tr[rt].fa)rt=tr[rt].fa;return rt;} 
inline void rotate(int rt)
{
	int fa1=tr[rt].fa,fa2=tr[fa1].fa;
	bool dir1=getdir(rt,fa1),dir2=getdir(fa1,fa2);
	connect(tr[rt].son[dir1^1],fa1,dir1);
	connect(rt,fa2,dir2);
	connect(fa1,rt,dir1^1);
	update(fa1),update(rt);
	return;
}
inline void splay(int rt,int top)
{
	if(!top)root=rt;
    while(tr[rt].fa^top)
    {
        int fa1=tr[rt].fa,fa2=tr[fa1].fa;
        bool dir1=getdir(rt,fa1),dir2=getdir(fa1,fa2);
        if(fa2^top)rotate(dir1==dir2?fa1:rt);
        rotate(rt);
    }
    return;
}
inline void deletenode(int rt)
{
	splay(rt,0);
    tr[tr[rt].son[0]].fa=0;
	tr[rt].son[0]=0;
	update(rt);
	return;
}
inline int query(int x,int y)
{
	if(x==y)return num[x];
	int xfa=findfa(x),yfa=findfa(y);
	if(xfa^yfa)return -1;
	splay(x,0),splay(y,x);
	bool dir=getdir(y,tr[y].fa);
	return tr[tr[y].son[dir^1]].sum+num[x]+num[y];
}
inline void merge(int x,int y)
{
	x=findfa(x),y=findfa(y);
	if(x==y)return;
	if(tr[x].dep>tr[y].dep)
	{
		while(tr[x].son[0])x=tr[x].son[0];
		tr[x].son[0]=y,tr[y].fa=x;
		splay(y,0);
	}
	else
	{
		while(tr[y].son[1])y=tr[y].son[1];
		tr[y].son[1]=x,tr[x].fa=y;
		splay(x,0);
	}
	return;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)num[i]=read(),update(i);
	for(int i=1;i<=m;++i)
	{
		char op[3];
		cin>>op;
		switch(op[0])
		{
			case 'M':
			{
				int x=read(),y=read();
				merge(x,y);
				break;
			}
			case 'D':
			{
				deletenode(read());
				break;
			}
			case 'Q':
			{
				int x=read(),y=read();
				write(query(x,y)),puts("");
				break;
			}
			default:break;
		}
	}
	return 0;
}

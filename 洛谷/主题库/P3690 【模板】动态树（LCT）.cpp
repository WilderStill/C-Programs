#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
	return;
}
const int M=1e5+10;
struct SplayNode
{
	int fa,son[2],sum,val;
	bool mk;
}tr[M];
inline bool getdir(int rt){return tr[tr[rt].fa].son[1]==rt;}
inline bool notroot(int rt){return tr[tr[rt].fa].son[0]==rt||tr[tr[rt].fa].son[1]==rt;}
inline void update(int rt){tr[rt].sum=tr[tr[rt].son[0]].sum^tr[rt].val^tr[tr[rt].son[1]].sum;return;}
inline void pushdown(int rt)
{
    if(!tr[rt].mk)return;
    swap(tr[rt].son[0],tr[rt].son[1]);
    tr[tr[rt].son[0]].mk^=1;
    tr[tr[rt].son[1]].mk^=1;
    tr[rt].mk=0;
    return;
}
inline void pushall(int rt)
{
    if(notroot(rt))pushall(tr[rt].fa);
    pushdown(rt);
}
inline void rotate(int rt)
{
    int fa1=tr[rt].fa,fa2=tr[fa1].fa;
    bool dir=getdir(rt);
    if(notroot(fa1))tr[fa2].son[getdir(fa1)]=rt;
    tr[tr[rt].son[dir^1]].fa=fa1;
    tr[fa1].son[dir]=tr[rt].son[dir^1];
    tr[rt].son[dir^1]=fa1;
    tr[fa1].fa=rt;
    tr[rt].fa=fa2;
    update(fa1);update(rt);
    return;
}
inline void splay(int rt)
{
    pushall(rt);
    for(int fa=tr[rt].fa;fa=tr[rt].fa,notroot(rt);rotate(rt))
        if(notroot(fa))rotate(getdir(rt)==getdir(fa)?fa:rt);
    return;
}
inline void access(int rt){for(int s=0;rt;s=rt,rt=tr[rt].fa)splay(rt),tr[rt].son[1]=s,update(rt);return;}
inline void makeroot(int rt){access(rt),splay(rt);tr[rt].mk^=1;return;}
inline int findroot(int rt)
{
	access(rt),splay(rt);
	while(tr[rt].son[0])pushdown(rt),rt=tr[rt].son[0];
	splay(rt);
	return rt;
}
inline void link(int x,int y)
{
	makeroot(x);
	if(findroot(y)!=x)tr[x].fa=y;
	return;
}
inline void cut(int x,int y)
{
	makeroot(x);
	if(findroot(y)==x&&tr[y].fa==x&&!tr[y].son[0])tr[x].son[1]=tr[y].fa=0;
	update(x);
	return;
}
inline void split(int x,int y){makeroot(x),access(y),splay(y);return;}
inline void print(int x,int y)
{
	split(x,y);
	write(tr[y].sum);
	puts("");
	return;
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)tr[i].val=read();
	for(int i=1;i<=m;++i)
	{
		int op=read(),x=read(),y=read();
		switch(op)
		{
			case 0:print(x,y);break;
			case 1:link(x,y);break;
			case 2:cut(x,y);break;
			case 3:makeroot(x),splay(x),tr[x].val=y;break;
			default:break;
		}
	}
	return 0;
}
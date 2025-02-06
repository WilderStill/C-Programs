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
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
constexpr int M=1000010;
int tot,root;
struct node{int fa,size,val,son[2];}tr[M];
inline int newnode(int fa,int val){tr[++tot].fa=fa;tr[tot].val=val;return tot;}
inline void update(int rt){tr[rt].size=tr[tr[rt].son[0]].size+tr[tr[rt].son[1]].size+1;return;}
inline bool getdir(int rt,int fa){return tr[fa].son[1]==rt;}
inline void connect(int rt,int fa,bool dir){tr[fa].son[dir]=rt;tr[rt].fa=fa;return;}
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
        if(fa2!=top)rotate(dir1==dir2?fa1:rt);
        rotate(rt);
    }
    return;
}
inline void deletenode(int rt)
{
	splay(rt,0);
    if(tr[rt].son[1])
    {
        int tp=tr[rt].son[1];
        while(tr[tp].son[0])tp=tr[tp].son[0];
        splay(tp,rt);
        connect(tr[rt].son[0],tp,0);
        root=tp;
        tr[tp].fa=0;
        update(root);
    }
    else
	{
		root=tr[rt].son[0];
		tr[root].fa=0;
	}
	return;
}
inline void insert(int&rt,int fa,int val)
{
	if(!rt){rt=newnode(fa,val);splay(rt,0);return;}
    if(val<tr[rt].val){insert(tr[rt].son[0],rt,val);return;}
    else{insert(tr[rt].son[1],rt,val);return;}
}
inline void remove(int rt,int val)
{
    if(val==tr[rt].val){deletenode(rt);return;}
    if(val<tr[rt].val){remove(tr[rt].son[0],val);return;}
    else{remove(tr[rt].son[1],val);return;}
}
inline int queryrank(int val)
{
    int rt=root,rk=1,pre=0;
    while(rt)
    {
        if(val<=tr[rt].val)pre=rt,rt=tr[rt].son[0];
        else rk+=tr[tr[rt].son[0]].size+1,rt=tr[rt].son[1];
    }
    if(pre)splay(pre,0);
    return rk;
}
inline int querynum(int rk)
{
    int rt=root;
    while(rt)
    {
        if(tr[tr[rt].son[0]].size+1==rk){splay(rt,0);break;}
        if(tr[tr[rt].son[0]].size>=rk)rt=tr[rt].son[0];
        else rk-=tr[tr[rt].son[0]].size+1,rt=tr[rt].son[1];
    }
    return tr[rt].val;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int op=read(),x=read();
		switch(op)
		{
			case 1:insert(root,0,x);break;
			case 2:remove(root,x);break;
			case 3:write(queryrank(x));puts("");break;
			case 4:write(querynum(x));puts("");break;
			case 5:write(querynum(queryrank(x)-1));puts("");break;
			case 6:write(querynum(queryrank(x+1)));puts("");break;
			default:break;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
ui m,n,seed,lst=7;
inline ui kdg(ui&seed,ui last,const ui m){seed=seed*17+last;return seed%m+1;}
int tot,bin,root,idx[1000010];
struct score
{
	int ria,rib;
	inline bool operator<(const score b)const{return ria==b.ria?rib<b.rib:ria>b.ria;}
	inline bool operator<=(const score b)const{return ria==b.ria?rib<=b.rib:ria>b.ria;}
}kkk[1000010];
struct node
{
    int size,key,l,r;
	score v;
}p[2000010];
inline void combine(int k){p[k].size=p[p[k].l].size+p[p[k].r].size+1;}
inline int newnode(score val)
{
	int id;
	if(bin)id=idx[bin--];
	else id=++tot;
    p[++tot].v=val;
	p[tot].key=rand();
    p[tot].l=p[tot].r=0;
	p[tot].size=1;
    return tot;
}
inline void split(int k,score val,int &l,int &r)
{
    if(!k){l=r=0;return;}
    if(p[k].v<=val){l=k;split(p[k].r,val,p[k].r,r);}
    else{r=k;split(p[k].l,val,l,p[k].l);}
    combine(k);
}
inline int merge(int l,int r)
{
    if(!l||!r)return l+r;
    if(p[l].key<p[r].key)
	{
        p[l].r=merge(p[l].r,r);
        combine(l);
        return l;
    }
    else
	{
        p[r].l=merge(l,p[r].l);
        combine(r);
        return r;
    }
}
inline void insert(score val)
{
    int l,r;
    split(root,val,l,r);
    root=merge(merge(l,newnode(val)),r);
}
inline void remove(score val)
{
    int x,y,z;
	score tp=val;
	tp.rib--;
    split(root,val,x,z);
    split(x,tp,x,y);
    idx[++bin]=y;
    y=merge(p[y].l,p[y].r);
    root=merge(merge(x,y),z);
}
inline int queryrank(score val)
{
    int x,y,ans;
    val.rib--;
    split(root,val,x,y);
    ans=p[x].size+1;
    root=merge(x,y);
    return ans-1;
}
int main()
{
	int T=read();
	while(T--)
	{
		m=read(),n=read(),seed=read();
		root=tot=bin=0;
		for(int i=1;i<=m;++i)kkk[i].ria=kkk[i].rib=0,insert(kkk[i]);
		for(int i=1;i<=n;++i)
		{
			int id=kdg(seed,lst,m),val=kdg(seed,lst,m);
			remove(kkk[id]);
			++kkk[id].ria;
			kkk[id].rib+=val;
			insert(kkk[id]);
			write(lst=queryrank(kkk[id]));puts("");
		}
	}
	return 0;
}

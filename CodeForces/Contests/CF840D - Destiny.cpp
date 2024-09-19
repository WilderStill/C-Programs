#include<bits/stdc++.h>
#define dg 100
#define M 300010
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
int n,m,block,num[M],vis[M],tans[M],blo[M];
struct node
{
	int l,r,k,blo,id;
	bool operator<(const node &x) const
	{
		if(blo^x.blo)return blo<x.blo;
		return blo&1?r>x.r:r<x.r;
	}
}q[M];
inline void add(int x){++vis[num[x]];}
inline void remove(int x){--vis[num[x]];}
int main()
{
	srand(time(0));
	n=read(),m=read();
	block=n/sqrt(m+1)+1;
	for(int i=1;i<=n;++i)num[i]=read();
	for(int i=1;i<=m;++i)
		q[i].l=read(),q[i].r=read(),q[i].k=read(),q[i].id=i,q[i].blo=q[i].l/block;
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;++i)
	{
		while(r<q[i].r)add(++r);
		while(l>q[i].l)add(--l);
		while(r>q[i].r)remove(r--);
		while(l<q[i].l)remove(l++);
		int ans=-1;
		for(int t=1;t<=dg;++t)
		{
			int id=rand()*rand()%(r-l+1)+l;
			if(vis[num[id]]*q[i].k>r-l+1)
				if(ans==-1||ans>num[id])ans=num[id];
		}
		tans[q[i].id]=ans;
	}
	for(int i=1;i<=m;++i)write(tans[i]),puts("");
	return 0;
}

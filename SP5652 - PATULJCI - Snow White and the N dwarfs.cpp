#include<bits/stdc++.h>
#define dg 40
#define M 500010
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
int n,m,k,l=1,r,block,num[M],vis[M],tans[M],blo[M];
struct node
{
	int l,r,id;
}q[M];
inline bool cmp(node x,node y)
{
	if((x.l-1)/block==(y.l-1)/block) return x.r<y.r;
	return x.l/block<y.l/block;
}
inline void add(int x){++vis[num[x]];}
inline void remove(int x){--vis[num[x]];}
int main()
{
	srand(time(0));
	n=read();int b=read();
	for(int i=1;i<=n;++i)num[i]=read();
	m=read();
	block=n/sqrt(m+1)+1;
	for(int i=1;i<=n;++i)blo[i]=(i-1)/block+1;
	for(int i=1;i<=m;++i)
		q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;++i)
	{
		while(r<q[i].r)add(++r);
		while(l>q[i].l)add(--l);
		while(r>q[i].r)remove(r--);
		while(l<q[i].l)remove(l++);
		int ans=-1;
		for(int t=1;t<=dg;++t)
		{
			int id=rand()%(r-l+1)+l;
			if(vis[num[id]]*2>r-l+1)
				if(ans==-1||ans>num[id])ans=num[id];
		}
		tans[q[i].id]=ans;
	}
	for(int i=1;i<=m;++i)
	{
		if(tans[i]!=-1)printf("yes %d\n",tans[i]);
		else printf("no\n");
	}
	return 0;
}


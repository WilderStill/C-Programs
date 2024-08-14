#include<bits/stdc++.h>
#define M 1145141
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
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
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int n,m,ans,l=1,r,block,pos[M],pre[M],suf[M],num[M],vis[M],blo[M],ans1[M];
struct node
{
	int l,r,id,res;
}q[M];
inline bool cmp(node x,node y)
{
	if(blo[x.l]^blo[y.l])return x.l<y.l;
	if(blo[x.l]&1)return x.r<y.r;
	return x.r>y.r;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)num[i]=read();
	m=read();
	block=n/sqrt(m);
	for(int i=1;i<=n;++i)blo[i]=(i-1)/block+1;
	for(int i=1;i<=m;++i)
	{
		q[i].l=read(),q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=n;++i)pre[i]=pos[num[i]],pos[num[i]]=i;
    memset(pos,0x3f3f3f3f,sizeof pos);
	for(int i=n;i;--i)suf[i]=pos[num[i]],pos[num[i]]=i;
	for(int i=1;i<=m;++i)
	{
		while(l>q[i].l)ans+=(suf[--l]>r);
		while(l<q[i].l)ans-=(suf[l++]>r);
		while(r>q[i].r)ans-=(pre[r--]<l);
		while(r<q[i].r)ans+=(pre[++r]<l);
		ans1[q[i].id]=ans;
	}
	for(int i=1;i<=m;++i)write(ans1[i]),putchar('\n');
	return 0;
}

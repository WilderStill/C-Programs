#include<bits/stdc++.h>
#define M 400000007
#define N 1145141
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
int n,m,ans,l=1,r,block;
int num[N],mp[M],blo[N];
struct node{
	int l,r,id,res;
}q[N];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return x.l<y.l;
	if(!(blo[x.l]%2))return x.r>y.r;//奇偶优化:多加了行判断
	return x.r<y.r;
}
void add(int x)
{
	int p=num[x]/31,q=num[x]%31;
	if(mp[p]+(1ll<<q)<(1ll<<31))
	{
		ans-=__builtin_popcountll(mp[p]);
		mp[p]+=(1ll<<q);
		ans+=__builtin_popcountll(mp[p]);
		return;
	}
	ans-=31-q;
	mp[p]=mp[p]&((1ll<<q)-1);
	p++;
	while(mp[p]==((1ll<<31)-1))mp[p++]=0,ans-=31;
	ans-=__builtin_popcountll(mp[p]);
	mp[p]++;
	ans+=__builtin_popcountll(mp[p]);
} 
void remove(int x)
{
	int p=num[x]/31,q=num[x]%31;
	if(mp[p]-(1ll<<q)>=0)
	{
		ans-=__builtin_popcountll(mp[p]);
		mp[p]-=(1ll<<q);
		ans+=__builtin_popcountll(mp[p]);
		return;
	}
	ans+=31-q;
	mp[p]|=((1ll<<31)-(1ll<<q));
	p++;
	while(!mp[p])mp[p++]=(1ll<<31)-1,ans+=31;
	ans-=__builtin_popcountll(mp[p]);
	mp[p]--;
	ans+=__builtin_popcountll(mp[p]);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)num[i]=read();
	block=n/sqrt(m);
	for(int i=1;i<=n;i++)blo[i]=(i-1)/block+1;
	for(int i=1;i<=m;i++)
	{
		q[i].l=read(),q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(l<q[i].l)remove(l++);
		while(r>q[i].r)remove(r--);
		q[i].res=ans;
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)write(q[i].res),putchar('\n');
	return 0;
}

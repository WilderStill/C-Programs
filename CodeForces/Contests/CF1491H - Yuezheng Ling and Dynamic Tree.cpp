#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
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
	putchar(x%10+48);
	return;
}
int n,m,blen,tot,L[400010],R[400010],blo[400010],cnt[400010],pa[400010],fa[400010];
ll mk[400010];
inline void update(int x)
{
	if(cnt[blo[x]]<=blen)pa[x]=blo[x]^blo[fa[x]]?fa[x]:pa[fa[x]];
	return;
}
inline void modify(int l,int r,int x)
{
	if(blo[l]==blo[r])
	{
		for(int i=l;i<=r;++i)fa[i]=max(1,fa[i]-x);
		for(int i=l;i<=R[blo[r]];++i)update(i);
		return;
	}
	for(int i=l;i<=R[blo[l]];++i)fa[i]=max(1,fa[i]-x);
	for(int i=l;i<=R[blo[R[blo[l]]]];++i)update(i);
	for(int i=blo[l]+1;i<blo[r];++i)
	{
		if(cnt[i]>blen)
		{
			mk[i]=min(mk[i]+x,n*1ll);
			++cnt[i];
			continue;
		}
		for(int j=L[i];j<=R[i];++j)fa[j]=max(1,fa[j]-x),update(j);
		++cnt[i];
	}
	for(int i=L[blo[r]];i<=r;++i)fa[i]=max(1,fa[i]-x);
	for(int i=L[blo[r]];i<=R[blo[r]];++i)update(i);
	return;
}
#define findpa(x) (cnt[blo[x]]<=blen?pa[x]:max(1ll,fa[x]-mk[blo[x]]))
#define findfa(x) (cnt[blo[x]]<=blen?fa[x]:max(1ll,fa[x]-mk[blo[x]]))
inline int query(int l,int r)
{
	while(l^r)
	{
		int lpa=findpa(l),rpa=findpa(r);
		if(blo[lpa]^blo[rpa])blo[lpa]>blo[rpa]?l=lpa:r=rpa;
		else if(lpa^rpa)lpa>rpa?l=lpa:r=rpa;
		else l>r?l=findfa(l):r=findfa(r);
	}
	return l;
}
int main()
{
	n=read(),m=read();
	blen=sqrt(n),tot=(n-1)/blen+1;
	for(int i=1;i<=tot;++i)
	{
		L[i]=(i-1)*blen+1,R[i]=i==tot?n:i*blen;
		for(int j=L[i];j<=R[i];++j)blo[j]=i;
	}
	fa[1]=pa[1]=1;
	for(int i=2;i<=n;++i)fa[i]=read(),update(i);
	for(int i=1;i<=m;++i)
	{
		int op=read(),l=read(),r=read();
		if(op==1)
		{
			int x=read();
			modify(l,r,x);
		}
		else write(query(l,r)),puts("");
	}
	return 0;
}

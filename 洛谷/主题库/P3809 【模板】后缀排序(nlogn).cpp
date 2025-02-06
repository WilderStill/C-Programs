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
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
const int DG=1000010;
int n,m,rk[DG],sa[DG],lkz[DG],c[DG];
char s[DG];
inline void tsort()
{
	memset(c,0,sizeof (int)*(m+1));
	for(int i=1;i<=n;++i)++c[rk[i]];
	for(int i=1;i<=m;++i)c[i]+=c[i-1];
	for(int i=n;i;--i)sa[c[rk[lkz[i]]]--]=lkz[i];
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	m='z';
	for(int i=1;i<=n;++i)lkz[i]=i,rk[i]=s[i];
	tsort();
	for(int w=1,p=0;w<n;m=p,w<<=1)
	{
		p=0;
		for(int i=n;i>n-w;--i)lkz[++p]=i;
		for(int i=1;i<=n;++i)if(sa[i]>w)lkz[++p]=sa[i]-w;
		tsort();
		swap(lkz,rk);
		rk[sa[1]]=1;
		for(int i=2,p=1;i<=n;++i)rk[sa[i]]=lkz[sa[i]]==lkz[sa[i-1]]&&lkz[sa[i]+w]==lkz[sa[i-1]+w]?p:++p;
	}
	for(int i=1;i<=n;++i)rk[sa[i]]=i;
	for(int i=1;i<=n;++i)write(sa[i]),putchar(' ');
	return 0;
}

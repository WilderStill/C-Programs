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
const int DG=2000010;
int w,rk[DG],sa[DG],lkz[DG];
char s[DG];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		char ch=getchar();
		while(ch<'A'||ch>'Z')ch=getchar();
		rk[i]=rk[2*(n+1)-i]=s[i]=ch;
	}
	n=n*2+1;
	for(int i=1;i<=n;++i)sa[i]=i;
	for(w=1;w<n;w<<=1)
	{
		sort(sa+1,sa+n+1,[](int x,int y){return rk[x]==rk[y]?rk[x+w]<rk[y+w]:rk[x]<rk[y];});
		memcpy(lkz,rk,sizeof rk);
		for(int i=1,p=0;i<=n;++i)rk[sa[i]]=lkz[sa[i]]==lkz[sa[i-1]]&&lkz[sa[i]+w]==lkz[sa[i-1]+w]?p:++p;
	}
	int l=1,r=n-1>>1,tot=0;
	while(l<=r)
	{
		putchar(rk[l]<rk[n-r+1]?s[l++]:s[r--]);
		if(++tot%80==0)puts("");
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
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
int w,rk[DG],sa[DG],lkz[DG],h[DG];
char s[DG];
signed main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)sa[i]=i,rk[i]=s[i];
	for(w=1;w<n;w<<=1)
	{
		sort(sa+1,sa+n+1,[](int x,int y){return rk[x]==rk[y]?rk[x+w]<rk[y+w]:rk[x]<rk[y];});
		memcpy(lkz,rk,sizeof rk);
		for(int i=1,p=0;i<=n;++i)rk[sa[i]]=lkz[sa[i]]==lkz[sa[i-1]]&&lkz[sa[i]+w]==lkz[sa[i-1]+w]?p:++p;
	}
	for(int i=1,k=0;i<=n;++i)
	{
		if(!rk[i])continue;
		if(k)--k;
		while(s[i+k]==s[sa[rk[i]-1]+k])++k;
		h[rk[i]]=k;
	}
	int ans=n*(n+1)/2;
	for(int i=1;i<=n;++i)ans-=h[i];
	write(ans);
	return 0;
}

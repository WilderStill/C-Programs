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
int n,w,T,nt[DG],s[DG],fm[DG],rk[DG],sa[DG],lkz[DG],h[DG],buk[DG];
inline int check(int x)
{
	int ln=0,tp=1;
	if(fm[sa[1]])++ln,++buk[fm[sa[1]]];
	for(int i=2;i<=n;++i)
	{
		if(h[i]<x)
		{
			if(ln>=T)return 1;
			for(int j=tp;j<i;++j)buk[fm[sa[j]]]=0;
			ln=0,tp=i;
			if(fm[sa[i]])++ln,++buk[fm[sa[i]]];
			continue;
		}
		if(!buk[fm[sa[i]]]&&fm[sa[i]])++ln,++buk[fm[sa[i]]];
	}
	return ln>=T;
}
int main()
{
	T=read();
	int l=1,r=0;
	for(int i=1;i<=T;++i)
	{
		int t=read();r=max(t,r);
		for(int j=1;j<=t;++j)nt[++n]=read(),fm[n]=i;
		nt[++n]=i+101,fm[n]=0;
	}
	for(int i=1;i<=n;++i)s[i]=nt[i]-nt[i-1];
	s[1]=0;
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
	int ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	write(ans+1);
	return 0;
}

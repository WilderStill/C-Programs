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
int w,rk[DG],sa[DG],lkz[DG];
char s[DG];
int main()
{
	scanf("%s",s+1);
	int t=strlen(s+1);
	memcpy(s+t+1,s+1,t); 
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)sa[i]=i,rk[i]=s[i];
	for(w=1;w<n;w<<=1)
	{
		sort(sa+1,sa+n+1,[](int x,int y){return rk[x]==rk[y]?rk[x+w]<rk[y+w]:rk[x]<rk[y];});
		memcpy(lkz,rk,sizeof rk);
		for(int i=1,p=0;i<=n;++i)rk[sa[i]]=lkz[sa[i]]==lkz[sa[i-1]]&&lkz[sa[i]+w]==lkz[sa[i-1]+w]?p:++p;
	}
	for(int i=1;i<=n;++i)if(sa[i]<=t)putchar(s[sa[i]+t-1]);
	return 0;
}

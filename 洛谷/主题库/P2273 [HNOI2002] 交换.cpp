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
const int Dg=2;
int num[10010];
int main()
{
	int n=read(),m=read();
	for(int i=2;i<=n;++i)num[i]=Dg;
	for(int i=1;i<=m;++i)
	{
		int a=read(),b=read();
		if(a>1&&num[a]<num[b])num[a]=num[b];
		if(num[b])--num[b];
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans+=num[i];
	write(ans);
	return 0;
}

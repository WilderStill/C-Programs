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
int num[32770];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)num[i]=read();
	int ans=num[1];
	for(int i=2;i<=n;++i)
	{
		int mn=0x3f3f3f3f;
		for(int j=1;j<i;++j)mn=min(mn,abs(num[i]-num[j]));
		ans+=mn;
	}
	write(ans);
	return 0;
}

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
int num[200010];
int main()
{
	int n=read(),m=read(),sum=0;
	for(int i=1;i<=n;++i)sum+=(num[i]=read());
	for(int i=1;i<=m;++i)
	{
		char op[2];
		scanf("%s",op);
		int x=read(),y=read();
		if(op[0]=='A')
		{
			if(x==1)
			{
				write(sum),puts("");
				continue;
			}
			int res=0;
			for(int i=y;i<=n;i+=x)res+=num[i];
			write(res);puts("");
		}
		else
		{
			sum-=num[x];
			num[x]=y;
			sum+=num[x];
		}
	}
}

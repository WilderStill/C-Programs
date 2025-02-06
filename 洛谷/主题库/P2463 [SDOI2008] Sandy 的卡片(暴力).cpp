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
int m[1010][1010],pk,mn=1e9;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		m[i][0]=read();
		if(mn>=m[i][0])mn=m[i][0],pk=i;
		if(m[i][0]==1)
		{
			write(1);
			return 0;
		}
		for(int j=1;j<=m[i][0];++j)m[i][j]=read();
	}
	for(int i=1;i<=n;++i)
	{
		m[i][0]=m[i][0]-1;
		for(int j=1;j<=m[i][0];++j)m[i][j]=m[i][j+1]-m[i][j];
	}
	int ans=0;
	for(int l=1;l<=m[pk][0];++l)
	{
		int r=m[pk][0];
		for(int i=1;i<=n;++i)
		{
			if(i==pk)continue;
			int mr=0;
			for(int j=1;j<=m[i][0];++j)
			{
				if(m[i][j]==m[pk][l])
				{
					int ps=j,nr=l;
					while(m[i][ps]==m[pk][nr]&&ps<=m[i][0]&&nr<=r)++ps,++nr;
					mr=max(mr,nr-1);
				}
			}
			r=min(r,mr);
		}
		ans=max(ans,r-l+1);
	}
	write(ans+1);
	return 0;
}

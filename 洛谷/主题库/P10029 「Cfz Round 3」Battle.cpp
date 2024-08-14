#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int main()
{
	int m,n,p,t;
	t=read();
	while(t--)
	{
		bool fg=0;
		n=read();m=read();p=read();
		for(int i=1;i<=100;i++)
		{
			if(m%p==m){printf("Alice\n");fg=1;break;}
			else if(n%p==n){printf("Bob\n");fg=1;break;}
			else n-=(n%p),m-=(m%p);
		}
		if(!fg)printf("Lasting Battle\n");
	}
	return 0;
}

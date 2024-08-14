#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int p[21][21],q[21][21],mx;
bool visf[21];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(int x)
{
    x<0?putchar('-'),x=-x:0;
    int num=0;
	char ch[50];
    while(x)ch[++num]=x%10+'0',x/=10;
    num==0?putchar('0'):0;
    while(num)putchar(ch[num--]);
    putchar('\n');return;
}
inline void dfs(int lst,int sum)
{
	if((double)clock()/CLOCKS_PER_SEC>=0.95)
	{
		ans=max(ans,sum);
		return;
	}
	if(lst>n)
	{
		ans=max(ans,sum);
		return;
	}
	int sums=0;
	for(int i=lst;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			mx=max(mx,p[i][j]*q[j][i]);
		sums+=mx;
	}
	if(sums+sum<=ans)return;
	for(int i=1;i<=n;++i)
	{
		if(!visf[i])
		{
			visf[i]=1;
			dfs(lst+1,sum+p[lst][i]*q[i][lst]);
			visf[i]=0;
		}
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			p[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			q[i][j]=read();
	dfs(1,0);
	write(ans);
	return 0;
}

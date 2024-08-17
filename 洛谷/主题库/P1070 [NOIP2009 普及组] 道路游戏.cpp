#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
	return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,m,p,ans,cost[1005],coin[1005][1005],f[2][1005][1005];
int main()
{
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			coin[i][j]=read();
	for(int i=1;i<=n;++i)cost[i]=read();
	memset(f,-INF,sizeof f);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
		{
			if(i==1)f[i&1][j][0]=f[i&1][j][1]=coin[j][i&1]-cost[j];
			else for(int k=1;k<=p;++k)
			{
				int tp=(j+k-1)%n?(j+k-1)%n:n;
				if(k==1)f[i&1][j][1]=f[(i-1)&1][0][k-1]+coin[tp][i]-cost[j];
				else f[i&1][j][k]=f[(i-1)&1][j][k-1]+coin[tp][i];
				f[i&1][j][0]=max(f[i&1][j][0],f[i&1][j][k]);
			}
			f[i&1][0][0]=max(f[i&1][0][0],f[i&1][j][0]);
		}
	write(f[m&1][0][0]);
    return 0;
} 

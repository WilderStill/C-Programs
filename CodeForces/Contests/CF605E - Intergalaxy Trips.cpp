#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
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
double syh[1010][1010],dgzz[1010],divdg[1010];
bool vis[1010];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			syh[i][j]=1.0*read()/100.0;
	if(n==1)
	{
		puts("0");
		return 0;
	}
	vis[n]=1;
	for(int i=1;i<=n;++i)
		dgzz[i]=1,divdg[i]=1-syh[i][n];
	for(int i=1;i<=n;++i)
	{
		double dugou=1e18;
		int bigdg=0;
		for(int j=1;j<=n;++j)
			if(!vis[j]&&dgzz[j]/(1-divdg[j])<dugou)
				dugou=dgzz[j]/(1-divdg[j]),bigdg=j;
		if(bigdg==1)
		{
			printf("%.10lf",dgzz[1]/(1-divdg[1]));
			return 0;
		}
		vis[bigdg]=1;
		for(int j=1;j<=n;++j)
			dgzz[j]+=dgzz[bigdg]/(1-divdg[bigdg])*syh[j][bigdg]*divdg[j],divdg[j]*=(1-syh[j][bigdg]);
	}
	return 0;
}


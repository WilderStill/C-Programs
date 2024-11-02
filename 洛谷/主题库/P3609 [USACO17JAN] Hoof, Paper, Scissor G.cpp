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
inline void file()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}
const int win[3][3]={{1,0,0},{0,1,0},{0,0,1}};
int f[100010][21][3],syh;
int main()
{
	//file();
	int n=read(),k=read();
	for(int i=1,tp,df;i<=n;++i)
	{
		char op[2];
		scanf("%s",op);
		if(op[0]=='H')tp=0;
		if(op[0]=='P')tp=1;
		if(op[0]=='S')tp=2;
		f[i][0][0]=f[i-1][0][0]+win[0][tp];
		f[i][0][1]=f[i-1][0][1]+win[1][tp];
		f[i][0][2]=f[i-1][0][2]+win[2][tp];
		for(int j=1;j<=k;++j)
		{
			f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+win[0][tp]);
			f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+win[1][tp]);
			f[i][j][2]=max(f[i][j][2],f[i-1][j][2]+win[2][tp]);
			syh=0;
			syh=max({syh,f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j-1][2]});
			f[i][j][0]=max(f[i][j][0],syh+win[0][tp]);
			f[i][j][1]=max(f[i][j][1],syh+win[1][tp]);
			f[i][j][2]=max(f[i][j][2],syh+win[2][tp]);
		}
	}
	for(int j=0;j<=k;++j)syh=max({syh,f[n][j][0],f[n][j][1],f[n][j][2]});
	write(syh);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

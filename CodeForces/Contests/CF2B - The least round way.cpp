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
int num[1010][1010][2],f[1010][1010][2];
bool fg;
inline void print(int x,int y,int ed,int op)
{
    if(x==1&&y==1)
	{
		putchar(op?'D':'R'); 
		return;
	}
    if(x==1)
	{
		print(x,y-1,ed,0);
		putchar(op?'D':'R');
		return;
	}
    if(y==1)
	{
		print(x-1,y,ed,1);
		putchar(op?'D':'R');
		return;
	}
    if(f[x][y][ed]==f[x-1][y][ed]+num[x][y][ed])
	{
        print(x-1,y,ed,1);
		if(!(~op))return;
		putchar(op?'D':'R');
		return;   
    }
	else
	{
		print(x,y-1,ed,0);
		if(!(~op))return;
		putchar(op?'D':'R');
		return;
    }
}
int main()
{
	int n=read(),pozx=0,pozy=0;
	memset(f,0x3f3f3f3f,sizeof f);
	f[1][1][0]=f[1][1][1]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int x=read();
			if(!x)
			{
				fg=1,pozx=i,pozy=j;
				num[i][j][0]=num[i][j][1]=1;
			}
			else
			{
				while(!(x%2))++num[i][j][0],x/=2;
				while(!(x%5))++num[i][j][1],x/=5;
			}
		}
    for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
            if(i>1)f[i][j][0]=min(f[i][j][0],f[i-1][j][0]),f[i][j][1]=min(f[i][j][1],f[i-1][j][1]);
            if(j>1)f[i][j][0]=min(f[i][j][0],f[i][j-1][0]),f[i][j][1]=min(f[i][j][1],f[i][j-1][1]);
            f[i][j][0]+=num[i][j][0],f[i][j][1]+=num[i][j][1];
        }
    if(min(f[n][n][0],f[n][n][1])>1&&fg)
	{
        write(1),puts("");
        for(int i=1;i<pozx;++i)putchar('D');
        for(int i=1;i<pozy;++i)putchar('R');
        for(int i=pozx;i<n;++i)putchar('D');
        for(int i=pozy;i<n;++i)putchar('R');
        return 0;
    }
    if(f[n][n][0]<f[n][n][1])write(f[n][n][0]),puts(""),print(n,n,0,-1);
    else write(f[n][n][1]),puts(""),print(n,n,1,-1);
    return 0;
}


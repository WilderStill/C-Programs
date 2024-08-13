#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
ld f[111][111][111],rans,sans,pans;
int main()
{
	int r=read(),s=read(),p=read();
	f[r][s][p]=1;
	for(int i=r;~i;--i)
		for(int j=s;~j;--j)
			for(int k=p;~k;--k)
			{
				ld sum=i*j+j*k+i*k;
				if(i&&j)f[i][j-1][k]+=f[i][j][k]*i*j/sum;
				if(j&&k)f[i][j][k-1]+=f[i][j][k]*j*k/sum;
				if(k&&i)f[i-1][j][k]+=f[i][j][k]*i*k/sum;
			}
	for(int i=1;i<=r;++i)rans+=f[i][0][0];
	for(int j=1;j<=s;++j)sans+=f[0][j][0];
	for(int k=1;k<=p;++k)pans+=f[0][0][k];
	printf("%.9Lf %.9Lf %.9Lf",rans,sans,pans);
    return 0;
}


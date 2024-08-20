#include<bits/stdc++.h>
using namespace std;
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
double f[1010][1010];
int main()
{
	int w=read(),b=read();
	for(int i=1;i<=w;++i)f[i][0]=1.0,f[i][1]=1.0*i/(i+1);
	for(int i=1;i<=w;++i)
		for(int j=2;j<=b;++j)
			f[i][j]=(1.0*i/(i+j))+(1.0*j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2))*f[i-1][j-2]+(1.0*j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*(j^2?f[i][j-3]:0));
    printf("%.9lf",f[w][b]);
	return 0;
}


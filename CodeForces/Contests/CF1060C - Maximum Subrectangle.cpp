#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
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
int suma[2010],sumb[2010],fa[2010],fb[2010];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)suma[i]=suma[i-1]+read();
	for(int i=1;i<=m;++i)sumb[i]=sumb[i-1]+read();
	memset(fa,INF,sizeof fa);
	memset(fb,INF,sizeof fb);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			fa[i-j+1]=min(fa[i-j+1],suma[i]-suma[j-1]);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=i;++j)
			fb[i-j+1]=min(fb[i-j+1],sumb[i]-sumb[j-1]);
	int x=read(),ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(1ll*fa[i]*fb[j]<=x)ans=max(ans,i*j);
	write(ans);
	return 0;
}

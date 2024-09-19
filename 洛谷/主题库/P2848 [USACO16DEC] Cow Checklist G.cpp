#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
    return x*f;
}
inline void write(ll x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
ll h[1010][2],g[1010][2],f[1010][1010][2];
int main()
{
	auto pow2=[](ll x){return x*x;};
    int n=read(),m=read();
	memset(f,INF,sizeof f);
    f[1][0][0]=0;
    for(int i=1;i<=n;++i)h[i][0]=read(),h[i][1]=read();
    for(int i=1;i<=m;++i)g[i][0]=read(),g[i][1]=read();
	for(int i=2;i<=n;++i)f[i][0][0]=f[i-1][0][0]+pow2(h[i][0]-h[i-1][0])+pow2(h[i][1]-h[i-1][1]);
    for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			f[i][j][0]=min(f[i-1][j][0]+pow2(h[i][0]-h[i-1][0])+pow2(h[i][1]-h[i-1][1]),f[i-1][j][1]+pow2(h[i][0]-g[j][0])+pow2(h[i][1]-g[j][1])),
			f[i][j][1]=min(f[i][j-1][1]+pow2(g[j][0]-g[j-1][0])+pow2(g[j][1]-g[j-1][1]),f[i][j-1][0]+pow2(h[i][0]-g[j][0])+pow2(h[i][1]-g[j][1]));
    write(f[n][m][0]);
	return 0;
}

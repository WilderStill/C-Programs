#include<bits/stdc++.h>
#define N 3010
using namespace std;
inline int readi()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline unsigned readu()
{
	unsigned x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x;
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
inline void write(unsigned x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
unsigned A,B,C,ans,a[N][N],sum[N][N],tg[N][N];
inline unsigned this_is_rand_dg()
{
    A^=A<<16;A^=A>>5;A^=A<<1;
    unsigned t=A;
    A=B;B=C;C^=t^A;
    return C;
}
int main()
{
	int n=readi(),m=readi(),q=readi();
	A=readu(),B=readu(),C=readu();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=this_is_rand_dg();
	int len=max(n,m);
	for(int i=1;i<=len;++i)
		for(int j=1;j<=len;++j)
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    for(int i=1;i<=len;++i)
		for(int j=1;j<=len;++j)
			tg[i][j]=tg[i-1][j+1]+sum[j][i]-sum[j-1][i];
    while(q--)
    {
        int x=this_is_rand_dg()%n+1;
		int y=this_is_rand_dg()%m+1;
		int k=this_is_rand_dg()%min(x,y)+1;
        ans=ans*233+(sum[x][y]-sum[x-k][y])-(tg[y-1][x-k+1]-tg[max(y-k-1,0)][x+1]);
    }
    write(ans);
    return 0;
}


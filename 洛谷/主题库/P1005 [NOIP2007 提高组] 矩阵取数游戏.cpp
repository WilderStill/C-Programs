#include<bits/stdc++.h>
using namespace std;
inline int readi()
{
	register int x=0,f=1;
    register char ch=getchar();
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
inline __int128 read()
{
    register __int128 x=0,f=1;
    register char ch=getchar();
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
inline void write(__int128 x)
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
__int128 ans,pw[83],f[81][81];
int num[81];
int main()
{
	int n=readi(),m=readi();
	pw[0]=1;for(int i=1;i<=m+2;++i)pw[i]=pw[i-1]<<1;
	for(register int syh=1;syh<=n;++syh)
	{
		memset(f,0,sizeof f);
		for(register int i=1;i<=m;++i)num[i]=readi();
		for(register int i=1;i<=m;++i)for(register int j=m;j>=i;--j)f[i][j]=max({f[i][j],f[i-1][j]+pw[m-j+i-1]*num[i-1],f[i][j+1]+pw[m-j+i-1]*num[j+1]}); 
		__int128 maxn=0;
		for(register int i=1;i<=m;++i)maxn=max(maxn,f[i][i]+pw[m]*num[i]);
		ans+=maxn;
	}
	write(ans);
	return 0;
}



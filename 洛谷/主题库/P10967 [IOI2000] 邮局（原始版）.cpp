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
int num[310],dis[310][310],f[310][310];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)num[i]=read();
	sort(num+1,num+n+1);
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
        {
            int pos=i+j>>1;
            for(int k=i;k<=j;++k)dis[i][j]+=abs(num[pos]-num[k]);
        }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i)f[i][1]=dis[1][i];
    for(int i=1;i<=n;++i)
        for(int j=2;j<=min(m,i);++j)
            for(int k=j-1;k<i;++k)
                f[i][j]=min(f[i][j],f[k][j-1]+dis[k+1][i]);
    write(f[n][m]);
    return 0;
}


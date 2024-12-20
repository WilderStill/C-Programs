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
int num[3012],f[3012][312],dis[3012][3012];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)num[i]=read();
	stable_sort(num+1,num+n+1);
	memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
           dis[i][j]=dis[i][j-1]+num[j]-num[i+j>>1];
    for(int i=0;i<=n;++i)f[i][1]=dis[1][i];
    for(int i=1;i<=n;++i)
        for(int j=2;j<=min(m,i);++j)
            for(int k=j-1;k<i;++k)
                f[i][j]=min(f[i][j],f[k][j-1]+dis[k+1][i]);
    printf("%d",f[n][m]);
    return 0;
}

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
int n,d1,d2;
int ans[3][5010][5010],cnt[2][2];
void solve(int d,int id)
{
    int k=0;
    while(d%4==0)d/=4,k+=1;
    if(d%4==3)return;
    if(d%4==1)
	{
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                ans[id][i][j]=((i-1)/(1<<k)+(j-1)/(1<<k))&1;
    }
	else
	{
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                ans[id][i][j]=((i-1)/(1<<k))&1;
    }
}

int main()
{
    scanf("%d%d%d",&n,&d1,&d2);
    n <<= 1;
    solve(d1,1),solve(d2,2);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            ++cnt[ans[1][i][j]][ans[2][i][j]];
    int x,y;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            if(cnt[i][j]>=n*n/4)
                x=i,y=j;
    int tot = 0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(ans[1][i][j]==x&&ans[2][i][j]==y)
			{
                printf("%d %d\n",i-1,j-1);
                tot+=1;
                if(tot>=n*n/4)exit(0);
            }
    return 0;
}

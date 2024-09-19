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
int pos[60][60][5010],pre[60][60][5010],f[60][60][5010],cnt[60][5010],
a[5010],b[5010],c[5010],lsh[5010],ans[5010];
inline void solve(int l,int r,int k)
{
	if(l>r)return;
	k=pre[l][r][k];
	int tpos=pos[l][r][k];
	ans[tpos]=lsh[k];
	solve(l,tpos-1,k);
	solve(tpos+1,r,k);
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)a[i]=read(),b[i]=read(),c[i]=lsh[i]=read();
	sort(lsh+1,lsh+m+1);
	int len=unique(lsh+1,lsh+m+1)-lsh-1;
	for(int i=1;i<=m;++i)c[i]=lower_bound(lsh+1,lsh+len+1,c[i])-lsh;
	for(int i=n;i;--i)
		for(int j=i;j<=n;++j)
		{
			for(int k=i;k<=j;++k)memset(cnt[k],0,sizeof cnt[k]);
			for(int k=1;k<=m;++k)
				if(i<=a[k]&&b[k]<=j)
					for(int l=a[k];l<=b[k];++l)
						++cnt[l][c[k]];
			for(int k=i;k<=j;++k)
				for(int l=len;l;--l)
					cnt[k][l]+=cnt[k][l+1];
			for(int k=len;k;--k)
			{
				int res=0;
				for(int l=i;l<=j;++l)
				{
					int tp=f[i][l-1][k]+f[l+1][j][k]+cnt[l][k]*lsh[k];
					if(res<=tp)res=tp,pos[i][j][k]=l;
				}
				res>=f[i][j][k+1]?(f[i][j][k]=res,pre[i][j][k]=k):
				(f[i][j][k]=f[i][j][k+1],pre[i][j][k]=pre[i][j][k+1]);
			}
		}
	write(f[1][n][1]),puts("");
	solve(1,n,1);
	for(int i=1;i<=n;++i)write(ans[i]),putchar(' ');
	return 0;
}


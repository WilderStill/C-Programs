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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int cnt1,cnt2,match[1010],ln[1010][1010],rw[1010][1010];
bool mp[1010][1010],vis[1010];
char ch[1010][1010];
inline bool found(int x)
{
	for(int i=1;i<=cnt2;++i)
		if(mp[x][i]&&!vis[i])
		{
			vis[i]=1;
			if(!match[i]||found(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	int n=read(),m=read(),ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch[i]+1);
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='*')
			{
				if(j==1||ch[i][j-1]!='*')ln[i][j]=++cnt1;
				else ln[i][j]=cnt1;
			}	
	}
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
			if(ch[i][j]=='*')
			{
				if(i==1||ch[i-1][j]!='*')rw[i][j]=++cnt2;
				else rw[i][j]=cnt2;
				mp[ln[i][j]][rw[i][j]]=1;
			}
	for(int i=1;i<=cnt1;++i)
	{
		memset(vis,0,sizeof vis);
		ans+=found(i);
	}
	write(ans);
	return 0;
}

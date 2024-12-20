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
int mp[1010][1010],vis[1010],match[1010],kb[1010],n,m,e,ans;
bool found(int x)
{
	for(int i=1;i<=n;i++)
		if(mp[x][i])
		{
			if(vis[i])continue;
			vis[i]=1;
			if(!match[i]||found(match[i]))
			{ 
				match[i]=x; 
				kb[x]=i;
				return 1;
			}
		} 
	return 0;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int u=read()+1,v=read()+1;
        mp[i][u]=1;
		mp[i][v]=1;
    }
    for(int i=1;i<=m;++i)
    {
        memset(vis,0,sizeof vis);
        if(found(i))++ans;
        else break;
    }
    write(ans),puts("");
    for(int i=1;i<=ans;++i)write(kb[i]-1),puts("");
    return 0;
}


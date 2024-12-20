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
int vis[1000010],match[1000010],n,m,now,ans;
vector<int>mp[1000100];
bool found(int x)
{
	for(auto i:mp[x])
	{
		if(vis[i]==now)continue;
		vis[i]=now;
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
    n=read();
    for(int i=1;i<=n;++i)
    {
        int u=read(),v=read();
        mp[u].push_back(i);
        mp[v].push_back(i);
    }
    for(int i=1;i<=10000;++i)
    {
    	++now;
        if(found(i))++ans;
        else break;
    }
    write(ans);
    return 0;
}


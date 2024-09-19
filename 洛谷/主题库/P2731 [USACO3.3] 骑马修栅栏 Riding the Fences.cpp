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
int ind[1026],to[1026],mp[1026][1026],maxn=0,minn=0x3f3f3f3f;
stack<int>ans;
void dfs(int pos)
{
	for(int i=minn;i<=maxn;++i)
	{ 
		if(mp[pos][i])
		{
			--mp[pos][i],--mp[i][pos];
			dfs(i);
		} 	
	}
	ans.push(pos); 
}
int main()
{
	int n=read(); 
	for(int i=1;i<=n;++i)
	{
		int u=read(),v=read();
		++mp[u][v],++mp[v][u];
		++ind[v],++ind[u];
		minn=min({minn,u,v});
		maxn=max({maxn,u,v});
	}
	int s=1; 
	bool syh=0; 
	for(int i=minn;i<=maxn;++i)
	{
		if(ind[i]&1)
		{
			s=i;
			syh=1;
			break; 
		} 
	}
	dfs(syh?s:minn);
	while(!ans.empty())
	{
		write(ans.top()),putchar('\n');
		ans.pop();
	}
	return 0; 
}

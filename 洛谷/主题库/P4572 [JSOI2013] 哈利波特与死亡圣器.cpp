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
vector<int>mp[300010];
int f[300010];
inline void dfs(int pos,int fa,int x)
{
	int sum=0;
	for(auto to:mp[pos])
	{
		if(to==fa)continue;
		dfs(to,pos,x);
		sum+=f[to]+1; 
	}
	f[pos]=max(0,sum-x);
}
inline bool check(int x)
{
	dfs(1,0,x);
	return f[1];
}
int main()
{
	int n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		mp[u].emplace_back(v);
		mp[v].emplace_back(u);
	}
	int l=0,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	write(r);
    return 0;
}

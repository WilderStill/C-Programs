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
vector<int>mp[100010];
int oddis[100010],evdis[100010];
void bfs()
{
	memset(oddis,0x3f,sizeof oddis);
	memset(evdis,0x3f,sizeof evdis);
	queue<pair<int,int>>q;
	for(auto syh:mp[1])
	{
		oddis[syh]=1;
		q.push({syh,1});
	}
	while(!q.empty())
	{
		int u=q.front().first,v=q.front().second+1;
		q.pop();
		for(auto syh:mp[u])
		{
			if(v&1)
			{
				if(v<oddis[syh])
					oddis[syh]=v,q.push({syh,v});
			}	
			else
			{
				if(v<evdis[syh])
					evdis[syh]=v,q.push({syh,v});
			}
		}
	}
}
int main()
{
	int n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	bfs();
	for(int i=1;i<=q;++i)
	{
		int u=read(),v=read();
		if(v&1)puts(oddis[u]<=v?"Yes":"No");
		else puts(evdis[u]<=v?"Yes":"No");
	}
	return 0;
}


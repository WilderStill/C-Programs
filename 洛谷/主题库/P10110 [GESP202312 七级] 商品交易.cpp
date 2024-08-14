#include<bits/stdc++.h>
#define M 100010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
vector<int>mp[M];
int v[M],dis[M];
queue<int>q;
int main()
{
	int n=read(),m=read(),st=read()+1,ed=read()+1;
	for(int i=1;i<=n;++i)v[i]=read();
	for(int i=1,u,v;i<=m;++i)
	{
		u=read()+1,v=read()+1;
		mp[u].emplace_back(v);
	}
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[st]=0;
	q.push(st);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto v:mp[top])
			if(dis[v]>dis[top]+1)
			{
				dis[v]=dis[top]+1;
				q.push(v);	
			}
	}
	if(dis[ed]==0x3f3f3f3f)puts("No solution");
	else write(dis[ed]+v[ed]-v[st]);
	return 0;
}

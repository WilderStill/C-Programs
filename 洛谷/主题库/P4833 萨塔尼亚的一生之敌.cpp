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
struct node
{
	int to,nxt;
}edge[4000100];
int tot,hd[4000100];
void addedge(int u,int v)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
bool qvis[4000100],svis[4000100];
vector<int>stk,syh;
int bfs(int pos)
{
	int lkz=0;
	queue<int>q;
	q.push(pos);
	while(!q.empty())
	{
		int qtop=q.front();
		q.pop();
		qvis[qtop]=1;
		++lkz;
		for(int i=hd[qtop];i;i=edge[i].nxt)svis[edge[i].to]=1;
		auto tmp=stk;stk.clear();
		for(auto dg:tmp)
		{
			if(dg==pos)continue;
			if(svis[dg])stk.push_back(dg);
			else q.push(dg);
		}
		for(int i=hd[qtop];i;i=edge[i].nxt)svis[edge[i].to]=0;
	}
	return lkz;
}
int main()
{
	int n=read(),m=read();
	for(int i=0;i<m;++i)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	for(int i=1;i<=n;++i)stk.push_back(i);
	for(int i=1;i<=n;++i)if(!qvis[i])syh.push_back(bfs(i));
	sort(syh.begin(),syh.end());
	write(syh.size()),putchar('\n');
	for(auto kb:syh)write(kb),putchar(' ');
	return 0;
}

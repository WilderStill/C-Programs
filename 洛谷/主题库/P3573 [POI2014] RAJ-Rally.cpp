#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
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
struct edges
{
	int to,nxt;
}edge[1000100],egde[1000100];
int n,m,tot1,tot2,f[1000100],g[1000100],q[1000100],hd1[1000100],hd2[1000100],ind[1000100],idx[1000100];
inline void addedge(int u,int v)
{
	++ind[v];
	edge[++tot1].nxt=hd1[u];
	edge[tot1].to=v;
	hd1[u]=tot1;
	egde[++tot2].nxt=hd2[v];
	egde[tot2].to=u;
	hd2[v]=tot2;
}
inline void topol()
{
	int hd=0,tl=-1;
	for(int i=1;i<=n;++i)if(!ind[i])q[++tl]=i;
	for(int i=1;i<=n;++i)
	{
		int top=q[hd++];
		idx[i]=top;
		for(int i=hd1[top];i;i=edge[i].nxt)if(!(--ind[edge[i].to]))q[++tl]=edge[i].to;
	}
}
struct Heap
{
	priority_queue<int>num,del;
	inline void check_del(){while(!del.empty()&&num.top()==del.top())num.pop(),del.pop();}
	inline void insert(int val){check_del();num.push(val);}
	inline void erase(int val){check_del();del.push(val);}
	inline bool empty(){return num.size()-del.size()?0:1;}
	inline int size(){return num.size()-del.size();}
	inline int top(){check_del();return !empty()?num.top():0;}
}syh;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		addedge(u,v);
	}
	topol();
	for(int i=1;i<=n;++i)
	{
		int top=idx[i];
		for(int i=hd1[top];i;i=edge[i].nxt)
			f[edge[i].to]=max(f[edge[i].to],f[top]+1);
	}
	for(int i=n;i;--i)
	{
		int top=idx[i];
		for(int i=hd1[top];i;i=edge[i].nxt)
			g[top]=max(g[top],g[edge[i].to]+1);
	}
	int ansdis=INF,ans=0;
	for(int i=1;i<=n;++i)syh.insert(g[i]);
	for(int id=1;id<=n;++id)
	{
		int top=idx[id];
		syh.erase(g[top]);
		for(int i=hd2[top];i;i=egde[i].nxt)
			syh.erase(f[egde[i].to]+g[top]+1);
		int res=syh.top();
		if(res<ansdis)ansdis=res,ans=top;
		syh.insert(f[top]);
		for(int i=hd1[top];i;i=edge[i].nxt)
			syh.insert(f[top]+g[edge[i].to]+1);
	}
	write(ans),putchar(' '),write(ansdis);
    return 0;
}

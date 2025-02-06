#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
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
	putchar(x%10+'0');
	return;
}
typedef tuple<int,int,int> tk;
bitset<30010>vis[30010];
vector<int>doge[30010];
queue<tk>q;
bool dg[30010];
int st,ed;
inline void insert(int pos,int p,int cnt)
{
	if(!dg[pos])
	{
		dg[pos]=1;
		for(auto px:doge[pos])
			if(!vis[pos][px])
			{
				vis[pos][px]=1;
				q.emplace(pos,px,cnt);
			}
	}
	if(!vis[pos][p])
	{
		vis[pos][p]=1;
		q.emplace(pos,p,cnt);
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=0;i<m;++i)
	{
		int b=read(),p=read();
		if(!i)st=b;
		if(i==1)ed=b;
		doge[b].emplace_back(p);
	}
	if(st==ed)
	{
		puts("0");
		return 0;
	}
	insert(st,0,0);
	while(!q.empty())
	{
		int pos,p,cnt;
		tie(pos,p,cnt)=q.front();
		q.pop();
		if(pos-p==ed||pos+p==ed)
		{
			write(cnt+1);
			return 0;
		}
		if(pos-p>=0)insert(pos-p,p,cnt+1);
		if(pos+p<n)insert(pos+p,p,cnt+1);
	}
	puts("-1");
	return 0;
}

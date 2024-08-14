#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(long long x)
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
	int nxt,to;
}edge[1000010];
int n,tot,cnt,hd[1000010],cn[500010],vis[500010];
long long sum=0;
char s[500010],syh[500010];
void addedge(int u,int v)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	hd[u]=tot;
}
void dfs(int rt,long long res)
{
	syh[++cnt]=s[rt];
	if(syh[cnt]==')')
	{
		for(int i=cnt-1;i;--i)
		{
			if(syh[cnt]^syh[i])
			{
				cn[cnt]=cn[i-1]+1;
				res+=cn[cnt];
				vis[cnt]=i;
			}
			else if(vis[i])
			{
				i=vis[i];
				continue;
			}
			break;
		}
	}
	sum^=(rt*res);
	for(int i=hd[rt];i;i=edge[i].nxt)dfs(edge[i].to,res);
	vis[cnt]=cn[cnt]=0;
	--cnt;
	return;
}
int main()
{
	//freopen("brackets.in","r",stdin);
	//freopen("brackets.out","w",stdout);
	n=read();
	scanf("%s",s+1);
	for(int i=2;i<=n;++i)
	{
		int f=read();
		addedge(f,i);
	}
	dfs(1,0);
	write(sum);
    return 0;
}

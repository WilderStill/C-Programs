#include<bits/stdc++.h>
#define M 1000010
#define INF 0x3f3f3f3f
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
int hd[M],tot;
struct node
{
	int to,nxt;
}edge[M];
inline void addedge(int u,int v)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
int num[M],syh[M],vis[M];
stack<int>stk1,stk2;
inline void dfs(int pos,int val)
{
    vis[pos]=val;
    for(int i=hd[pos];i;i=edge[i].nxt)
    {
    	int v=edge[i].to;
        if(!vis[v])dfs(v,3-val);
        else if(vis[v]==val)
        {
        	puts("0");
			exit(0);
		}
    }
}
int main()
{
    int n=read(),minn=INF;
    for(int i=1;i<=n;++i)num[i]=read();
    for(int i=n;i;--i)syh[i]=minn,minn=min(minn,num[i]);
    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(num[i]<num[j]&&num[i]>syh[j])addedge(i,j),addedge(j,i);
    for(int i=1;i<=n;++i)if(!vis[i])dfs(i,1);
    int pos=1;
    stk1.push(INF),stk2.push(INF);
    for(int i=1;i<=n;++i)
        if(vis[i]==1)
        {
            while(stk1.top()==pos)
            {
            	stk1.pop();
            	putchar('b'),putchar(' ');
            	++pos;
			}
            if(num[i]>stk1.top())
			{
				while(stk2.top()==pos)
	            {
	            	stk2.pop();
	            	putchar('d'),putchar(' ');
	            	++pos;
				}
			}
            while(stk1.top()==pos)
            {
            	stk1.pop();
            	putchar('b'),putchar(' ');
            	++pos;
			}
            stk1.push(num[i]);
            putchar('a'),putchar(' ');
        }
        else
        {
            while(true)
            {
            	if(stk1.top()==pos)
	            {
	            	stk1.pop();
	            	putchar('b'),putchar(' ');
	            	++pos;
	            	continue;
				}
				if(stk2.top()==pos)
	            {
	            	stk2.pop();
	            	putchar('d'),putchar(' ');
	            	++pos;
	            	continue;
				}
                break;
			}
			stk2.push(num[i]);
			putchar('c'),putchar(' ');
        }
    while(true)
    {
    	if(stk1.top()==pos)
        {
        	stk1.pop();
        	putchar('b'),putchar(' ');
        	++pos;
        	continue;
		}
		if(stk2.top()==pos)
        {
        	stk2.pop();
        	putchar('d'),putchar(' ');
        	++pos;
        	continue;
		}
		break;
	}
    return 0;
}

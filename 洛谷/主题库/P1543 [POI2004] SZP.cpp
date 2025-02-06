#include<bits/stdc++.h>
#define min(a,b) a<=b?a:b
using namespace std;
inline int read()
{
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x;
}
inline void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
const int M=1000002;
int cnt,rt,ind[M],mk[M],fa[M],vis[M];
queue<int>q;
int main()
{
	int n=read(),ans=0;
    for(int i=1;i<=n;++i)fa[i]=read(),ind[fa[i]]++;
    for(int i=1;i<=n;++i)if(!ind[i])q.push(i);
    while(!q.empty())
    {
        int u=q.front();
		q.pop();
        vis[u]=1;
        if(mk[u])
		{
			if(!(--ind[fa[u]]))
				q.push(fa[u]);
		}
        else if(!mk[fa[u]])
        {
            mk[fa[u]]=1,++ans;
            q.push(fa[u]);
        }
    }
    for(int i=1;i<=n;++i)
		if(!vis[i])
	    {
	        vis[rt=i]=1;
	        while(!vis[fa[rt]])
	        {
	            if(!mk[rt]&&!mk[fa[rt]])++ans,mk[fa[rt]]=1;
				rt=fa[rt];
	            vis[rt]=1;
	        }
	    }
    write(ans);
    return 0;
}

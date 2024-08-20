#include<bits/stdc++.h>
#define int long long
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
int n,m,k,ans,sc[2510],dep[2510];
bool vis[2510][2510];
vector<int>mp[2510],syh[2510];
queue<int>q;
bool syhcmp(int a,int b)
{
	return sc[a]>sc[b];
}
void bfs(int pos)
{
	memset(dep,-1,sizeof dep);
	q.push(pos);
	dep[pos]=0;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		if(top^pos)
		{
			vis[pos][top]=1;
            if((pos^1)&&vis[1][top])
			{
                syh[pos].emplace_back(top);
                sort(syh[pos].begin(),syh[pos].end(),syhcmp);
                if(syh[pos].size()>=4)syh[pos].pop_back();
            }
		}
		if(dep[top]>k)continue;
		for(auto to:mp[top])
		{
			if(!(~dep[to]))
			{
				dep[to]=dep[top]+1;
				q.push(to);
			}
        }
	}
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;++i)sc[i]=read();
	for(int i=1;i<=m;++i)
	{
        int u=read(),v=read();
        mp[u].emplace_back(v);
        mp[v].emplace_back(u);
    }
	for(int i=1;i<=n;++i)bfs(i);
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;++j)
			if(vis[i][j])
				for(auto p:syh[i])
					for(auto q:syh[j])
						if(p^j&&i^q&&p^q)
							ans=max(ans,sc[i]+sc[j]+sc[p]+sc[q]);
	write(ans);
    return 0;
}


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
int ind[100010],oud[100010],to[100010];
stack<int>ans;
vector<int>mp[100010];
void dfs(int pos)
{
	for(int i=to[pos];i<mp[pos].size();i=to[pos])
	{ 
	   to[pos]=i+1;
	   dfs(mp[pos][i]); 	
	}
	ans.push(pos); 
}
int main()
{
	int n=read(),m=read(); 
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		++oud[u],++ind[v];  
	}
	for(int i=1;i<=n;++i)sort(mp[i].begin(),mp[i].end());
	int s=1,cnt1=0,cnt2=0;  
	bool syh=1;
	for(int i=1;i<=n;++i)
	{
		if(oud[i]^ind[i])syh=0;
		if(oud[i]-ind[i]>1)
		{
			puts("No");
			return 0;
		}
		if(oud[i]-ind[i]==1)s=i,++cnt1;
		if(ind[i]-oud[i]==1)++cnt2; 
	}
	if(syh==1||(cnt1==cnt2)&&cnt1==1)
	{
		dfs(s);
		while(!ans.empty())
		{
			write(ans.top()),putchar(' ');
			ans.pop();
		}
		return 0;
	}
	puts("No");
	return 0; 
}

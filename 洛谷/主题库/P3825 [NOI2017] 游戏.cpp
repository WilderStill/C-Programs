#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,d,m,low[M],dfn[M],tim,sccnum,scc[M],mp[M],num[M][3];
bool isOut=1;
char str[M],s[M][3];
vector<int>edge[M];
stack<int>st;
bool inst[M];
inline int read()
{
	register int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void tarjan(int x)
{
    low[x]=dfn[x]=++tim;
    st.push(x);
    inst[x]=1;
    for(register int i=0;i<edge[x].size();++i)
	{
        int v=edge[x][i];
        if(!dfn[v])
		{
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
		else if(inst[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
	{
        ++sccnum;
        while(true)
		{
			int t=st.top();
            st.pop();
            scc[t]=sccnum;
            inst[t]=0;
			if(t==x)break;
		}
    }
}
inline void init()
{
	tim=sccnum=0;
	for(register int i=0;i<M;++i)edge[i].clear(),low[i]=dfn[i]=scc[i]=0;
}
inline bool two_sat()
{
	init();
	for(register int i=1,a,b;i<=m;++i)
    {
        if(str[num[i][1]]==s[i][1]+32)continue;
        if(str[num[i][1]]=='a')a=(s[i][1]=='B')?num[i][1]:num[i][1]+n;
        else a=(s[i][1]=='A')?num[i][1]:num[i][1]+n;
        if(str[num[i][2]]=='a')b=(s[i][2]=='B')?num[i][2]:num[i][2]+n;
        else b=(s[i][2]=='A')?num[i][2]:num[i][2]+n;
        if(str[num[i][2]]==s[i][2]+32)edge[a].push_back(a>n?a-n:a+n);
        else edge[a].push_back(b),edge[b>n?b-n:b+n].push_back(a>n?a-n:a+n);
    }
	for(register int i=1;i<=2*n;++i)if(!dfn[i])tarjan(i);
	for(register int i=1;i<=n;++i)if(scc[i]==scc[i+n])return 0;
	return 1;
}
inline void dfs(int syh)
{
	if(clock()>400000)
	{
		puts("-1");exit(0);
	}
	if(syh>d)
	{
		if(two_sat())isOut=0;
		return;
	}
	for(register int i=0;i<2;++i)
    {
        str[mp[syh]]=i+'a';
        dfs(syh+1);
        if(!isOut)return;
    } 
}
int main()
{
	n=read();read();
	for(register int i=1;i<=n;++i)
	{
		str[i]=getchar();
		if(str[i]=='x')mp[++d]=i;
	}
	m=read();
	int p=0;
	for(register int i=1;i<=m;++i)
	{
		scanf("%d %c %d %c",&num[i][1],&s[i][1],&num[i][2],&s[i][2]);
		if(num[i][1]==num[i][2])p++;
	}
	if(p==m)
	{
		printf("AA");return 0;
	}
	dfs(1);
	if(isOut){puts("-1");return 0;}
	for(register int i=1;i<=n;++i)
	{
		switch(str[i])
		{
			case 'a':{putchar((scc[i]<scc[i+n])?'B':'C');break;}
			case 'b':{putchar((scc[i]<scc[i+n])?'A':'C');break;}
			case 'c':{putchar((scc[i]<scc[i+n])?'A':'B');break;}
		}
	}
	return 0;
}

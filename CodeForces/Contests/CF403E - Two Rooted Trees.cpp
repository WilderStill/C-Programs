#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 200010
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
int n,st,sum;
bool vis[M][2];
vector<int>eat;
vector<pair<int,pair<int,int>>>tv[2];
struct SegmentTree
{
	int val,tot;
	vector<int>mp[M];
	struct edges
	{
		int from,to;
	}edge[M];
	int Tm,dfn[M],low[M],trl[M<<2],trr[M<<2];
	struct node
	{
		int syh,dg;
	};
	vector<node>tr[M<<2];
	void init()
	{
		memset(trr,-1,sizeof(trr));
	}
	void addedge(int u,int v)
	{
		edge[++tot].from=u;
		edge[tot].to=v;
		mp[u].push_back(v);
	}
	void dfs(int rt)
	{
		++Tm;
		dfn[rt]=Tm;
		for(auto v:mp[rt])dfs(v);
		low[rt]=Tm;
	}
	void modify(int rt,int l,int r,int posl,int posr,int v)
	{
		tr[rt].push_back({posr,v});
		trr[rt]=tr[rt].size()-1;
		if(l==r)
		{
			tot=max(rt,tot);
			return;
		}
		int mid=(l+r)>>1;
		if(posl<=mid)modify(lson,l,mid,posl,posr,v);
		else modify(rson,mid+1,r,posl,posr,v);
	}
	vector<int>query(int rt,int l,int r,int posl,int posr,int v,int cof)
	{
		vector<int>res;
		res.clear();
		if(tr[rt].empty())return res;
		if(posl<=l&&r<=posr)
		{
			if(cof==0)
			{
				while(trl[rt]<=trr[rt])
				{
					if(tr[rt][trr[rt]].syh<v)break;
					if(!vis[tr[rt][trr[rt]].dg][val^1])
					{
						vis[tr[rt][trr[rt]].dg][val^1]=1;
						res.push_back(tr[rt][trr[rt]].dg);
					}
					--trr[rt];
				}
			}
			else
			{
				while(trl[rt]<=trr[rt])
				{
					if(tr[rt][trl[rt]].syh>v)break;
					if(!vis[tr[rt][trl[rt]].dg][val^1])
					{
						vis[tr[rt][trl[rt]].dg][val^1]=1;
						res.push_back(tr[rt][trl[rt]].dg);
					}
					++trl[rt];
				}	
			}
			return res;
		}
		int mid=(l+r)>>1;
		if(posr<=mid)return query(lson,l,mid,posl,posr,v,cof);
		if(posl>mid)return query(rson,mid+1,r,posl,posr,v,cof);
		auto re1=query(lson,l,mid,posl,posr,v,cof);
		auto re2=query(rson,mid+1,r,posl,posr,v,cof);
		for(auto sub:re2)re1.push_back(sub);
		return re1;
	}
}T[2];
int main()
{
	//freopen("chick2.in","r",stdin);
	//freopen("chick.out","w",stdout);
	n=read();
	for(int m=0;m<=1;++m)
	{
		for(int i=2;i<=n;++i)
		{
			int x=read();
			T[m].addedge(x,i);
		}
	}
	for(int m=0;m<=1;++m)
	{
		T[m].dfs(1);
		T[m].init();
		T[m].val=m;
	}
	st=read();
	eat.push_back(st);
	for(int m=0;m<=1;++m)
		for(int i=1;i<n;++i)
		{
			if(m==0&&i==st)continue;
			int u=T[m^1].dfn[T[m].edge[i].from],v=T[m^1].dfn[T[m].edge[i].to];
			tv[m^1].push_back({v,{u,i}});
			tv[m^1].push_back({u,{v,i}});
		}
	for(int m=0;m<=1;++m)sort(tv[m].begin(),tv[m].end());
	for(int m=0;m<=1;++m)for(auto w:tv[m])T[m].modify(1,1,n,w.second.first,w.first,w.second.second);
	puts("Blue");
	write(st),puts("");
	int col=0;
	while(!eat.empty())
	{
		vector<int>res;
		for(auto u:eat)
		{
			vector<int>tmp;
			tmp=T[col].query(1,1,n,T[col].dfn[T[col].edge[u].to],T[col].low[T[col].edge[u].to],T[col].low[T[col].edge[u].to]+1,0);
			for(auto sub:tmp)res.push_back(sub);
			tmp=T[col].query(1,1,n,T[col].dfn[T[col].edge[u].to],T[col].low[T[col].edge[u].to],T[col].dfn[T[col].edge[u].to]-1,1);
			for(auto sub:tmp)res.push_back(sub);
		}
		eat.swap(res);
		if(eat.empty())break;
		sort(eat.begin(),eat.end());
		puts(!col?"Red":"Blue");
		for(auto ans:eat)write(ans),putchar(' ');
		puts("");
		col^=1;
	}
	return 0;
}

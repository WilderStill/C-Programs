#include<bits/stdc++.h>
#define M 2000010
using namespace std;
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
int ans[M];
struct ACM
{
	struct node
	{
		int son[8],val,fail,hd;
		vector<int> idx;
	}tr[M];
	struct edge
	{
		int hd,nxt;
	}edge[M];
	int rt,ecnt,tcnt;
	void insert(string s,int len,int id)
	{
		int p=rt;
		for(int i=0;i<len;++i)
		{
			int c;
			switch(s[i])
			{
				case 'A':{c=1;break;}
				case 'U':{c=2;break;}
				case 'G':{c=3;break;}
				case 'C':{c=4;break;}
				case '#':{c=5;break;}
				default:{c=6;break;}
			}
			if(!tr[p].son[c])tr[p].son[c]=++tcnt;
			p=tr[p].son[c];
		}
		tr[p].idx.push_back(id);
	}
	void build()
	{
		deque<int>q;
		for(int i=1;i<=6;++i)
			if(tr[0].son[i])
				q.push_back(tr[0].son[i]);
		while(!q.empty())
		{
			int u=q.front();
			q.pop_front();
			for(int i=1;i<=6;++i)
			{
				if(tr[u].son[i])
				{
					tr[tr[u].son[i]].fail=tr[tr[u].fail].son[i];
					q.push_back(tr[u].son[i]);
				}
				else
				{
					tr[u].son[i]=tr[tr[u].fail].son[i];
				}
			}
		}
		return;
	}
	void query(string s,int len)
	{
		int p=0;
		for(int i=1;i<=len;++i)
		{
			int c;
			switch(s[i])
			{
				case 'A':{c=1;break;}
				case 'U':{c=2;break;}
				case 'G':{c=3;break;}
				case 'C':{c=4;break;}
				case '#':{c=5;break;}
				default:{c=6;break;}
			}
			p=tr[p].son[c];
			++tr[p].val;
		}
		return;
	}
	void add(int tl,int hd)
	{
		edge[++ecnt].hd=hd;
		edge[ecnt].nxt=tr[tl].hd;
		tr[tl].hd=ecnt;
	}
	void dfs(int u)
	{
		for(int i=tr[u].hd;i;i=edge[i].nxt)
		{
			int v=edge[i].hd;
			dfs(v);
			tr[u].val+=tr[v].val;
		}
		for(auto i:tr[u].idx)ans[i]+=tr[u].val;
	}
	void failT()
	{
		for(int i=1;i<=tcnt;++i)add(tr[i].fail,i);
		dfs(rt);
	}
}qwq;
int n,m;
string s,t,t2;
int main()
{
	//freopen("gene.in","r",stdin);
	//freopen("gene.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		string tmp;
		cin>>tmp;
		s+="&"+tmp+"#"+tmp;
	}
	int lens=s.size()-1;
	for(int i=1;i<=m;++i)
	{
		cin>>t>>t2;
		t2+="#"+t;
		int lent=t2.size();
		qwq.insert(t2,lent,i);
	}
	qwq.build();
	qwq.query(s,lens);
	qwq.failT();
	for(int i=1;i<=m;++i)write(ans[i]),putchar('\n');
	return 0;
}

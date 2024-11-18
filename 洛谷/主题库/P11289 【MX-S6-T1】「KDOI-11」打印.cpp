#include<bits/stdc++.h>
#define int long long
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
struct node1
{
	int s,t,id;
	bool operator<(node1 b){return t<b.t;}
}wk[200010];
struct node2
{
	int v,id;
	bool operator<(const node2&b)const{return v==b.v?id>b.id:v>b.v;}
};
priority_queue<int,vector<int>,greater<int>>q1;
priority_queue<node2>q2;
int cnt[200010],hv[200010],shr[200010],lkz[200010],nxt[200010];
signed main()
{
	//freopen("print3.in","r",stdin);
	int n=read(),m=read();
	for(int i=1;i<=m;++i)q1.push(i);
	for(int i=1;i<=n;++i)wk[i]={read(),read(),i};
	sort(wk+1,wk+n+1);
	for(int i=1;i<=n;++i)
	{
		if(!q2.empty())
		{
			auto tp=q2.top();
			while(tp.v<=wk[i].t)
			{
				q2.pop();
				q1.push(tp.id);
				if(q2.empty())break;
				tp=q2.top();
			}
		}
		if(!q1.empty())
		{
			auto tp=q1.top();
			q1.pop();
			q2.push({wk[i].s+wk[i].t,tp});
			++cnt[tp];
			hv[wk[i].id]=tp;
		}
		else
		{
			auto tp=q2.top();
			q2.pop();
			q2.push({wk[i].s+tp.v,tp.id});
			++cnt[tp.id];
			hv[wk[i].id]=tp.id;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(shr[hv[i]])nxt[shr[hv[i]]]=i,shr[hv[i]]=i;
		if(!lkz[hv[i]])shr[hv[i]]=lkz[hv[i]]=i;
	}
	for(int i=1;i<=m;++i)
	{
		write(cnt[i]);
		for(int j=lkz[i];j;j=nxt[j])putchar(' '),write(j);
		puts("");
	}
	return 0;
}

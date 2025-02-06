#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define M 2000010
using namespace std;
using namespace __gnu_pbds;
using ll=long long; 
inline ll read()
{
	ll x=0,f=1;
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
inline void write(ll x)
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
struct node
{
    ll val,pos;
    inline bool operator<(const node&b)const
	{
		if(val!=b.val)return val<b.val;
		return pos>b.pos;
	}
};
__gnu_pbds::priority_queue<node>hp[M];
int fa[M];
bool del[M],vis[M];
inline int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
inline void merge(int x,int y)
{
	if(hp[x].size()>hp[y].size())
	{
		fa[y]=x;
		hp[x].join(hp[y]);
	}
    else
	{
		fa[x]=y;
		hp[y].join(hp[x]);
	}
}
int main()
{
	ll T=read(),W=read(),K=read();
	while(T--)
	{
		ll n=read(),m=read();
		memset(del,0,sizeof del);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;++i)
		{
            hp[i].clear();
            hp[i].push((node){read(),i});
            fa[i]=i;
        }
        for(int i=1;i<=m;++i)
        {
        	ll op=read();
        	if(op==2)
        	{
        		ll A=read();
        		del[A]=1;
			}
			if(op==3)
			{
				ll A=read(),B=read();
				ll Afa=findfa(A);
                while(!hp[Afa].empty()&&del[hp[Afa].top().pos])hp[Afa].pop();
                if(hp[Afa].empty())continue;
                ll tp=hp[Afa].top().val-B;
                hp[Afa].push({max(tp,0ll),hp[Afa].top().pos});
                hp[Afa].pop();
			}
			if(op==4)
			{
				ll A=read(),B=read();
				ll Afa=findfa(A),Bfa=findfa(B);
                if(Afa==Bfa)continue;
                merge(Afa,Bfa);
			}
		}
		ll evil=0,maxn=-1;
		for(int id=1;id<=n;++id)
		{
            ll idfa=findfa(id);
            while(!hp[idfa].empty()&&del[hp[idfa].top().pos])hp[idfa].pop();
            if(vis[idfa])continue;
            vis[idfa]=1;
            maxn=max(maxn,hp[idfa].empty()?0ll:hp[idfa].top().val);
            evil+=(hp[idfa].empty()?0ll:hp[idfa].top().val);
        }
        if(W==1)evil+=(maxn-maxn);
        if(W==2)evil-=maxn;
        if(W==3)evil+=maxn;
        if(!evil)
		{
			putchar('G');
			putchar('e');
			putchar('n');
			putchar('s');
			putchar('o');
			putchar('k');
			putchar('y');
			putchar('o');
			putchar(' ');
		}
		else if(evil>K)
		{
			putchar('H');
			putchar('e');
			putchar('l');
			putchar('l');
			putchar(' ');
		}
		else
		{
			putchar('H');
			putchar('e');
			putchar('a');
			putchar('v');
			putchar('e');
			putchar('n');
			putchar(' ');
		}
		write(evil);
		puts("");
	}
	return 0;
}

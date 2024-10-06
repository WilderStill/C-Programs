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
struct node
{
	int u,v,w;
	bool operator<(node b){return w<b.w;}
};
int n,maxn,fa[100010],num[100010];
vector<node>mp;
inline int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
inline void addedge(int x)
{
	for(int i=1;i*num[x]<=maxn;++i)
	{
		int pos=lower_bound(num+x+1,num+n+1,i*num[x])-num;
		if(pos<=n&&num[pos]/num[x]==i)mp.push_back({x,pos,num[pos]%num[x]});
	}
}
inline int Kruskal()
{
	int res=0;
	for(int i=0;i<mp.size();++i)
	{
		int ufa=findfa(mp[i].u);
		int vfa=findfa(mp[i].v);
		if(ufa==vfa)continue;
		fa[ufa]=vfa;
		res+=mp[i].w;
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)fa[i]=i,maxn=max(num[i]=read(),maxn);
	sort(num+1,num+n+1,[](int a,int b){return a<b;});
	n=unique(num+1,num+n+1)-num-1;
	for(int i=1;i<=n;++i)addedge(i);
	sort(mp.begin(),mp.end());
	write(Kruskal());
    return 0;
}


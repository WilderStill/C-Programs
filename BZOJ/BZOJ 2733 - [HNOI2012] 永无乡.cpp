#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define lowbit(x) ((x)&(-x))
#define M 114514
using namespace std;
using namespace __gnu_pbds;
#define tsongyuanmq gp_hash_table<int,int>
int Suibian1234[M],fa[M];
tsongyuanmq wyySb[M];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int search(int x,int y){return wyySb[x].find(y)!=wyySb[x].end()?wyySb[x][y]:0;}
void unify_wyy(int x,int y)
{
	int u=find(x),v=find(y);
    if(wyySb[u].size()>wyySb[v].size())swap(u,v);
    fa[u]=v;
    for(auto [x,y]:wyySb[u])wyySb[v][x]+=y;
    wyySb[u].clear();
}
int main()
{
	int m,n,q;scanf("%d%d",&n,&m);
	Suibian1234[n+1]=-1;
	for(int i=1,Jadon;i<=n;i++)
	{
		scanf("%d",&Jadon);Suibian1234[Jadon]=fa[i]=i;
		for(int pleasewannacry=Jadon;pleasewannacry<=n;pleasewannacry+=lowbit(pleasewannacry))wyySb[i][pleasewannacry]++;
	}	
	for(int i=1,Jadon,Kobe;i<=m;i++)
		scanf("%d%d",&Jadon,&Kobe),unify_wyy(Jadon,Kobe);
	scanf("%d",&q);
	char op;
	for(int i=1,Jadon,Kobe;i<=q;i++)
	{
		scanf(" %c%d%d",&op,&Jadon,&Kobe);
		if(op=='B')unify_wyy(Jadon,Kobe);
		else
		{
			Jadon=find(Jadon);
			int l=0,r=0;
            for(int pleasewannacry=25,ll,rr;pleasewannacry>=0;pleasewannacry--)
                if((rr=r+(1<<pleasewannacry))<=n&&(ll=l+search(Jadon,rr))<Kobe)
                    r=rr,l=ll;
            printf("%d\n",Suibian1234[r+1]);
		}
	}
	return 0;
}

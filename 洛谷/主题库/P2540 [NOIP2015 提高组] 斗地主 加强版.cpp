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
const int INF=0x3f3f3f3f;
int Card[17],Kind[5],KingBomb,res,ans,tp;
inline void dfs_split()
{
	int syh=0,tpKind[5];
	memcpy(tpKind,Kind,sizeof tpKind);
	while(tpKind[4])
    {
        if(tpKind[1]<2&&!tpKind[2])break;
        if(tpKind[1]>=2)
		{
			--tpKind[4];
			--tpKind[1];
			--tpKind[1];
			++syh;
			continue;
		}
        if(tpKind[2]>=2)
		{
			--tpKind[4];
			--tpKind[2];
			--tpKind[2];
			++syh;
			continue;
		}
        if(tpKind[2]==1)
		{
			--tpKind[4];
			--tpKind[2];
			++syh;
			continue;
		}
    }
    while(tpKind[3])
    {
        if(!tpKind[1]&&!tpKind[2])break;
        if(tpKind[1])
		{
			--tpKind[3];
			--tpKind[1];
			++syh;
			continue;
		}
        if(tpKind[2])
		{
			--tpKind[3];
			--tpKind[2];
			++syh;
			continue;
		}
    }
    for(int i=1;i<=4;++i)syh+=tpKind[i];
    tp=min(tp,syh);
	if(Kind[3])
	{
		--Kind[3];
		++Kind[1];
		++Kind[2];
		dfs_split();
		++Kind[3];
		--Kind[1];
		--Kind[2];
	}
    if(tpKind[4])
	{
		--Kind[4];
		++Kind[2];
		++Kind[2];
		dfs_split();
		++Kind[4];
		--Kind[2];
		--Kind[2];
		--Kind[4];
		++Kind[1];
		++Kind[3];
		dfs_split();
		++Kind[4];
		--Kind[1];
		--Kind[3];
	}
}
inline void dfs_smooth(int val)
{
	memset(Kind,0,sizeof Kind);
	for(int i=2;i<=16;++i)++Kind[Card[i]];
	tp=INF;
	dfs_split();
	res=min(res,tp+val);
	for(int i=3;i<=10;++i)
	{
		if(Card[i]>=1)
		{
			for(int j=i+1;j<=14;++j)
		    {
		        if(Card[j]<1)break;
				if(j-i<4)continue;
		        for(int k=i;k<=j;++k)--Card[k];
		        ++val;
				dfs_smooth(val);
				--val;
				for(int k=i;k<=j;++k)++Card[k];
		    }
		}
	}
	for(int i=3;i<=12;++i)
	{
		if(Card[i]>=2)
		{
			for(int j=i+1;j<=14;++j)
		    {
		        if(Card[j]<2)break;
				if(j-i<2)continue;
		        for(int k=i;k<=j;++k)--Card[k],--Card[k];
		        ++val;
				dfs_smooth(val);
				--val;
				for(int k=i;k<=j;++k)++Card[k],++Card[k];
		    }
		}
	}
	for(int i=3;i<=13;++i)
	{
		if(Card[i]>=3)
		{
			for(int j=i+1;j<=14;++j)
		    {
		        if(Card[j]<3)break;
				if(j-i<1)continue;
		        for(int k=i;k<=j;++k)--Card[k],--Card[k],--Card[k];
		        ++val;
				dfs_smooth(val);
				--val;
				for(int k=i;k<=j;++k)++Card[k],++Card[k],++Card[k];
		    }
		}
	}
}
int main()
{
	int T=read(),n=read();
	while(T--)
	{
		memset(Card,0,sizeof Card);
		ans=INF;
		for(int i=1;i<=n;++i)
		{
			int num=read(),col=read();
			if(!num)
			{
				++Card[14+col];
				continue;
			}
			if(num==1)
			{
				++Card[14];
				continue;
			}
			++Card[num];
		}
		KingBomb=min(Card[15],Card[16]);
		if(KingBomb)
		{
			Card[15]-=KingBomb;
			Card[16]-=KingBomb;
			res=INF;
			dfs_smooth(0);
			ans=min(ans,KingBomb+res);
			Card[15]+=KingBomb;
			Card[16]+=KingBomb;
		}
		res=INF;
		dfs_smooth(0);
		ans=min(ans,res);
		write(ans);
		puts(""); 
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

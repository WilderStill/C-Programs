#include<bits/stdc++.h>
#define int long long
#define M 514514
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,m,blen=710,lastans,tot,num[M],mode[710][710],lsh[M],size[M],cnt[M],block[M];
vector<int>pos[M];
struct node
{
	int l,r;
}blo[710];
void find_mode()
{
	int tot=0;
	for(int i=1;i<=n;i+=blen)blo[++tot]={i,min(i+blen-1,n)};
	for(int i=1;i<=tot;++i)
	{
		int ans=0;
		for(int j=blo[i].l;j<=blo[i].r;++j)block[j]=i;
		for(int j=i;j<=tot;++j)
		{
			for(int k=blo[j].l;k<=blo[j].r;++k)ans=max(ans,++cnt[num[k]]);
			mode[i][j]=ans;
		}
		for(int j=i;j<=tot;++j)
			for(int k=blo[j].l;k<=blo[j].r;++k)
				cnt[num[k]]=0;
	}
}
int query(int l,int r)
{
	int res=0;
	if(block[l]==block[r])
	{
		for(int i=l;i<=r;++i)res=max(res,++cnt[num[i]]);
		for(int i=l;i<=r;++i)cnt[num[i]]=0;
	}
	else
	{
		res=mode[block[l]+1][block[r]-1];
		for(int i=l;i<=blo[block[l]].r;++i)
			for(int tp=size[i];tp+res<pos[num[i]].size()&&pos[num[i]][tp+res]<=r;++res); 
		for(int i=blo[block[r]].l;i<=r;++i)
			for(int tp=size[i];tp-res>=0&&pos[num[i]][tp-res]>=l;++res); 
	}
	return res;
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)num[i]=lsh[i]=read();
	sort(lsh+1,lsh+n+1);
	int len=unique(lsh+1,lsh+n+1)-lsh;
	for(int i=1;i<=n;i++)
	{
		num[i]=lower_bound(lsh+1,lsh+len,num[i])-lsh;
		pos[num[i]].push_back(i);
		size[i]=pos[num[i]].size()-1;
	}
	find_mode();
	for(int i=1;i<=m;++i)
	{
		int l=read()^lastans,r=read()^lastans;
		write(lastans=query(l,r));
		puts("");
	}
	return 0;
}

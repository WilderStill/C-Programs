#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
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
inline void write(ll x)
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
ll tr[200010],ans;
int n,m,num[200010],pc[200010],cnt[200010];
inline void add(int x,ll v)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=v;
}
inline ll query(int x)
{
	ll res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		num[i]=read();
		pc[i]=i-1-query(num[i]);
		ans+=pc[i];
		++cnt[pc[i]];
		add(num[i],1);
	}
	memset(tr,0,sizeof tr);
	add(1,ans);
	int syh=0;
	for(int i=1;i<=n;++i)
	{
		syh+=cnt[i-1];
		add(i+1,syh-n);
	}
	for(int i=1;i<=m;++i)
	{
		int op=read(),x=read();
		x=min(x,n-1);
		if(op==1)
		{
			if(num[x]<num[x+1])
			{
				swap(num[x],num[x+1]);
				swap(pc[x],pc[x+1]);
				add(1,1);
				add(pc[x+1]+2,-1);
				++pc[x+1];
			}
			else
			{
				swap(num[x],num[x+1]);
				swap(pc[x],pc[x+1]);
				add(1,-1);
				add(pc[x]+1,1);
				--pc[x];
			}
		}
		else write(query(x+1)),puts("");
	}
    return 0;
}


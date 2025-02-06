#include<bits/stdc++.h>
using namespace std;
const int M=100010;
inline int read()
{
	int x=0,f=1;
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
inline void write(int x)
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
int n,m,tot,blen,blo[M],num[M],lsh[M],ans[M],cnt[M],sum[M],mk[M];
struct node
{
	int l,r,k,id;
	inline bool operator < (node b)
	{
		if(blo[l]^blo[b.l])return l<b.l;
		if(blo[l]&1)return r<b.r;
		return r>b.r;
	}
}q[M];
inline void add(int x)
{
    --mk[cnt[x]];
    --sum[blo[cnt[x]]];
    ++mk[++cnt[x]];
    ++sum[blo[cnt[x]]];  
}
inline void del(int x)
{
    --mk[cnt[x]];
    --sum[blo[cnt[x]]];
    ++mk[--cnt[x]];
    ++sum[blo[cnt[x]]];
}
inline int query(int k)
{
    int id=tot+1;
    for(int i=1;i<=tot;++i)
	{
        if(k-sum[i]<=0)
		{
			id=i;
			break;
		}
        k-=sum[i];
    }
    if(id==tot+1)return -1;
    for(int j=(id-1)*blen+1;j<=id*blen;++j)
	{
        if(k-mk[j]<=0)return j;
        k-=mk[j];
    }
}
int main()
{
	n=read(),m=read();
    blen=sqrt(n);
    tot=(n-1)/blen+1;
    for(int i=1;i<=n;++i)
	{
		lsh[i]=num[i]=read();
		blo[i]=(i-1)/blen+1;
	}
    sort(lsh+1,lsh+n+1);
    int len=unique(lsh+1,lsh+n+1)-lsh-1;
    for(int i=1;i<=n;++i)num[i]=lower_bound(lsh+1,lsh+len+1,num[i])-lsh;
    for(int i=1;i<=m;++i)q[i]={read(),read(),read(),i};
    sort(q+1,q+m+1);
    int l=1,r=0;
    for(int i=1;i<=m;++i)
	{
        while(l>q[i].l)add(num[--l]);
        while(r<q[i].r)add(num[++r]);
        while(l<q[i].l)del(num[l++]);
        while(r>q[i].r)del(num[r--]);
        ans[q[i].id]=query(q[i].k);
    }
    for(int i=1;i<=m;++i)write(ans[i]),puts("");
    return 0;
}

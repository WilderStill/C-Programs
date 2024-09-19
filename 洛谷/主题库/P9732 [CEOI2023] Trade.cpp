#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 250010
#define lson (rt<<1)
#define rson (rt<<1|1)
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
int n,k,len,tl=1,tr,ans=-INF,sum[M],c[M],s[M],v[M];
vector<pair<int,int>>dg;
struct node1
{
	int l,r,c,s;
}tr1[M<<2];
inline void update1(int rt)
{
	tr1[rt].c=tr1[lson].c+tr1[rson].c;
    tr1[rt].s=tr1[lson].s+tr1[rson].s;
}
inline void build1(int rt,int l,int r)
{
	tr1[rt].l=l,tr1[rt].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build1(lson,l,mid);
    build1(rson,mid+1,r);
}
inline void modify1(int rt,int l,int r,int val)
{
    if(r<tr1[rt].l||l>tr1[rt].r)return;
    if(tr1[rt].l>=l&&tr1[rt].r<=r)
	{
		tr1[rt].c+=val;
		tr1[rt].s=tr1[rt].c*v[tr1[rt].l];
        return;
    }
    modify1(lson,l,r,val);
    modify1(rson,l,r,val);
    update1(rt);
}
inline int queryc(int rt,int l,int r)
{
    if(l>tr1[rt].r||r<tr1[rt].l)return 0;
    if(l<=tr1[rt].l&&tr1[rt].r<=r)return tr1[rt].c;
    return queryc(lson,l,r)+queryc(rson,l,r);
}
inline int querys(int rt,int l,int r)
{
    if(l>tr1[rt].r||r<tr1[rt].l)return 0;
    if(l<=tr1[rt].l&&tr1[rt].r<=r)return tr1[rt].s;
    return querys(lson,l,r)+querys(rson,l,r);
}
inline int binarysearch(int md)
{
    md=tr1[1].c-md+1;
    int rt=1;
    while(tr1[rt].l^tr1[rt].r)md>tr1[lson].c?md-=tr1[lson].c,rt=rson:rt=lson;
    return tr1[rt].l;
}
inline int get_sum()
{
    int x=binarysearch(k);
    return querys(1,x+1,len)+(k-queryc(1,x+1,len))*v[x];
}
inline void add(int x){modify1(1,s[x],s[x],1);}
inline void del(int x){modify1(1,s[x],s[x],-1);}
inline void solve(int l,int r,int posl,int posr)
{
	int mid=(l+r)>>1,pos=0,res=-INF;
	for(int i=min(mid-k+1,posr);i>=max(posl,1ll);--i)
	{
		int pl=i,pr=mid;
		while(tl>pl)add(--tl);
		while(tr<pr)add(++tr);
		while(tl<pl)del(tl++);
		while(tr>pr)del(tr--);
		int val=get_sum()-(sum[tr]-sum[tl-1]);
		if(val>res)res=val,pos=i;
	}
	if(res>ans)ans=res,dg.clear();
	if(res==ans)dg.emplace_back(pos,mid);
	if(l==r)return;
	solve(l,mid,posl,pos);
	solve(mid+1,r,pos,posr);
}
struct node2
{
    int l,r,v;
}tr2[M<<2];
inline void build2(int rt,int l,int r)
{
	tr2[rt].l=l,tr2[rt].r=r,tr2[rt].v=INF;
    if(l==r)return;
    int mid=(l+r)>>1;
    build2(lson,l,mid);
    build2(rson,mid+1,r);
}
inline void modify2(int rt,int l,int r,int val)
{
    if(r<tr2[rt].l||l>tr2[rt].r)return;
    if(tr2[rt].l>=l&&tr2[rt].r<=r)
	{
		tr2[rt].v=min(tr2[rt].v,val);
        return;
    }
    modify2(lson,l,r,val);
    modify2(rson,l,r,val);
}
inline int query2(int rt,int l,int r)
{
    if(l>tr2[rt].r||r<tr2[rt].l)return INF;
    if(tr2[rt].l==tr2[rt].r)return tr2[rt].v;
    return min({tr2[rt].v,query2(lson,l,r),query2(rson,l,r)});
}
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(c[i]=read());
	for(int i=1;i<=n;++i)v[i]=s[i]=read();
	sort(v+1,v+n+1);
	len=unique(v+1,v+n+1)-v-1;
    for(int i=1;i<=n;++i)s[i]=lower_bound(v+1,v+len+1,s[i])-v;
    build1(1,1,len);
    solve(k,n,1,n);
    write(ans),puts("");
	sort(dg.begin(),dg.end());
	build2(1,1,n);
	int l=2;
	for(auto syh:dg)
	{
        int maxl=syh.first,r=syh.second;
        for(--l;l<=maxl;++l) 
        {
        	int pl=l,pr=r;
			while(tl>pl)add(--tl);
			while(tr<pr)add(++tr);
			while(tl<pl)del(tl++);
			while(tr>pr)del(tr--);
			int val=get_sum()-(sum[tr]-sum[tl-1]);
			if(val==ans)modify2(1,l,r,binarysearch(k));
		}
    }
    for(int i=1;i<=n;++i)write(s[i]>=query2(1,i,i));
    return 0;
}

#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
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
const int M=100010,INF=0x3f3f3f3f;
struct BST{vector<int>v;}tt[M*20];
inline void insert(int rt,int x){tt[rt].v.insert(lower_bound(tt[rt].v.begin(),tt[rt].v.end(),x),x);}
inline void del(int rt,int x){tt[rt].v.erase(lower_bound(tt[rt].v.begin(),tt[rt].v.end(),x));}
inline int getrk(int rt,int k){return lower_bound(tt[rt].v.begin(),tt[rt].v.end(),k)-tt[rt].v.begin();}
inline int getpre(int rt,int k)
{
	auto p=lower_bound(tt[rt].v.begin(),tt[rt].v.end(),k);
	if(p==tt[rt].v.begin())return -2147483647;
	return *(p-1);
}
inline int getsuf(int rt,int k)
{
	auto p=upper_bound(tt[rt].v.begin(),tt[rt].v.end(),k);
	if(p==tt[rt].v.end())return 2147483647;
	return *p;
}
struct Segment_node
{
	int l,r,prt;
}tr[M<<3];
int num[M];
inline void build(int rt,int l,int r)
{
	tr[rt].l=l,tr[rt].r=r,tr[rt].prt=rt;
	for(int i=l;i<=r;++i)insert(tr[rt].prt,num[i]);
	if(l==r)return;
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	return;
}
inline void modify(int rt,int pos,int val)
{
	del(tr[rt].prt,num[pos]);
	insert(tr[rt].prt,val);
	if(tr[rt].l==tr[rt].r)return;
	int mid=tr[rt].l+tr[rt].r>>1;
	if(pos<=mid)modify(lson,pos,val);
	else modify(rson,pos,val);
	return;
}
inline int qrk(int rt,int l,int r,int k)
{
	if(tr[rt].l>r||tr[rt].r<l)return 0;
	if(tr[rt].l>=l&&tr[rt].r<=r)return getrk(tr[rt].prt,k);
	return qrk(lson,l,r,k)+qrk(rson,l,r,k);
}
inline int qnum(int pl,int pr,int k)
{
	int l=0,r=INF,res=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(qrk(1,pl,pr,mid)<k)l=mid+1,res=mid;
		else r=mid-1;
	}
	return r;
}
inline int qpre(int rt,int l,int r,int k)
{
	if(tr[rt].l>r||tr[rt].r<l)return -2147483647;
	if(tr[rt].l>=l&&tr[rt].r<=r)return getpre(tr[rt].prt,k);
	else return max(qpre(lson,l,r,k),qpre(rson,l,r,k));
}
inline int qsuf(int rt,int l,int r,int k)
{
	if(tr[rt].l>r||tr[rt].r<l)return 2147483647;
	if(tr[rt].l>=l&&tr[rt].r<=r)return getsuf(tr[rt].prt,k);
	else return min(qsuf(lson,l,r,k),qsuf(rson,l,r,k));
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)num[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		char op[3];
		scanf("%s",op); 
		if(op[0]=='C')
		{
			int pos=read(),val=read();
			modify(1,pos,val);
			num[pos]=val;
		}
		else
		{
			int l=read(),r=read(),k=read();
			write(qnum(l,r,k)),puts("");
		}
	}
    return 0;
}


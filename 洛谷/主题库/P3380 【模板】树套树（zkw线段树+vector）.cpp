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
const int M=50010,INF=0x3f3f3f3f;
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
int num[M],N;
inline void modify_add(int pos,int val)
{
	for(int i=N+pos;i;i>>=1)insert(i,val);
}
inline void modify_del(int pos,int val)
{
	for(int i=N+pos;i;i>>=1)del(i,val);
}
inline int qrk(int l,int r,int k)
{
	int res=1;
    for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
        if(~l&1)res+=getrk(l^1,k);
        if(r&1)res+=getrk(r^1,k);
    }
	return res;
}
inline int qnum(int pl,int pr,int k)
{
	int l=0,r=INF,res=0;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(qrk(pl,pr,mid)<=k)l=mid;
		else r=mid-1;
	}
	return l;
}
inline int qpre(int l,int r,int k)
{
	int res=-2147483647;
    for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
        if(~l&1)res=max(res,getpre(l^1,k));
        if(r&1)res=max(res,getpre(r^1,k));
    }
	return res;
}
inline int qsuf(int l,int r,int k)
{
	int res=2147483647;
    for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
        if(~l&1)res=min(res,getsuf(l^1,k));
        if(r&1)res=min(res,getsuf(r^1,k));
    }
	return res;
}
int main()
{
	int n=read(),m=read();
	for(N=1;N<n;N<<=1);
	for(int i=1;i<=n;++i)num[i]=read(),modify_add(i,num[i]);
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==3)
		{
			int pos=read(),val=read();
			modify_del(pos,num[pos]);
			num[pos]=val;
			modify_add(pos,num[pos]);
		}
		else
		{
			int l=read(),r=read(),k=read();
			if(op==1)write(qrk(l,r,k)),puts("");
			if(op==2)write(qnum(l,r,k)),puts("");
			if(op==4)write(qpre(l,r,k)),puts("");
			if(op==5)write(qsuf(l,r,k)),puts("");
		}
	}
    return 0;
}


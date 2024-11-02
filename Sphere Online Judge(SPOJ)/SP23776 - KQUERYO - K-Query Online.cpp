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
    int ls,rs,sum;
    node(int _sum=0,int _ls=0,int _rs=0){sum=_sum,ls=_ls,rs=_rs;}
}tr[3200010];
int tot,INF=0x3f3f3f3f;
inline int newnode(int sum,int ls,int rs)
{
    tr[++tot]=node(sum,ls,rs);
    return tot;
}
inline int modify(int rt,int l,int r,int val)
{
    if(l==r)return newnode(tr[rt].sum+1,0,0);
    int mid=l+r>>1;
    if(val<=mid)return newnode(tr[rt].sum+1,modify(tr[rt].ls,l,mid,val),tr[rt].rs);
    return newnode(tr[rt].sum+1,tr[rt].ls,modify(tr[rt].rs,mid+1,r,val));
}
inline int query(int rtl,int rtr,int l,int r,int val)
{
    if(l==r)return tr[rtr].sum-tr[rtl].sum;
    int mid=l+r>>1;
    if(val>mid)return query(tr[rtl].rs,tr[rtr].rs,mid+1,r,val);
    else return query(tr[rtl].ls,tr[rtr].ls,l,mid,val)+tr[tr[rtr].rs].sum-tr[tr[rtl].rs].sum;
}
int root[3200010],lst=0;
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)root[i]=modify(root[i-1],1,INF,read());
    int m=read();
    for(int i=1;i<=m;++i)
	{
        int s=read()^lst,y=read()^lst,h=read()^lst;
        if(s<1)s=1;
        if(y>n)y=n;
        if(s>y)write(lst=0);
        else write(lst=query(root[s-1],root[y],1,INF,h+1));
        puts("");
    }
    return 0;
}

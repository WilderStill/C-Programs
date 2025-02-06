#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=4000004;
int n,blen,tot,blo[M],rt[M];
struct node{int l,r,mk,val;}tr[M<<1];
inline void pushdown(int rt,int l,int r)
{
    if(!tr[rt].mk)return;
    int mid=l+r>>1;
    if(tr[rt].mk<=mid)tr[rt].l=++tot,tr[tr[rt].l].mk=tr[rt].mk,tr[tr[rt].l].val=tr[rt].val;
    else tr[rt].r=++tot,tr[tr[rt].r].mk=tr[rt].mk,tr[tr[rt].r].val=tr[rt].val;
    tr[rt].mk=0;
    return;
}
inline void modify(int&rt,int l,int r,int pos,int val)
{
    if(!rt)
    {
        rt=++tot;
        tr[rt].mk=pos;
        tr[rt].val=val;
        return;
    }
    pushdown(rt,l,r);
    tr[rt].val+=val;
    if(l==r)return;
    int mid=l+r>>1;
    if(pos<=mid)modify(tr[rt].l,l,mid,pos,val);
    else modify(tr[rt].r,mid+1,r,pos,val);
    return;
}
inline int getdot(int rt,int l,int r,int pos)
{
    if(!rt||!pos)return 0;
    if(l==r)return tr[rt].val;
    if(tr[rt].mk)
    {
        if(pos>=tr[rt].mk)return tr[rt].val;
        else return 0;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)return getdot(tr[rt].l,l,mid,pos);
    else return tr[tr[rt].l].val+getdot(tr[rt].r,mid+1,r,pos);
}
inline int query(int x1,int x2,int y1,int y2)
{
    int l=blo[x1],r=blo[x2],res=0;
    if(l==r)
    {
        for(int i=x1;i<=x2;++i)res+=getdot(rt[i],1,n,y2)-getdot(rt[i],1,n,y1-1);
        return res;
    }
    for(int i=x1;i<=l*blen;++i)res+=getdot(rt[i],1,n,y2)-getdot(rt[i],1,n,y1-1);
    for(int i=l+1;i<r;++i)res+=getdot(rt[n+i],1,n,y2)-getdot(rt[n+i],1,n,y1-1);
    for(int i=(r-1)*blen+1;i<=x2;++i)res+=getdot(rt[i],1,n,y2)-getdot(rt[i],1,n,y1-1);
    return res;
}
signed main()
{
    int op=read();n=read();
    blen=sqrt(n);
    for(int i=1;i<=n;++i)blo[i]=(i-1)/blen+1;
    while(1)
    {
        int op=read();
        if(op==3)break;
        if(op==1)
        {
            int x=read(),y=read(),A=read();
            modify(rt[x],1,n,y,A);
            modify(rt[n+blo[x]],1,n,y,A);
        }
        if(op==2)
        {
            int x1=read(),y1=read(),x2=read(),y2=read();
            write(query(x1,x2,y1,y2)),puts("");
        }
    }
    return 0;
}
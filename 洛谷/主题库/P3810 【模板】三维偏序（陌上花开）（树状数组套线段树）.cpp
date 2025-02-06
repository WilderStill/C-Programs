#include<bits/stdc++.h>
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
const int M=400004;
int n,K,tot,cnt[M],rt[M];
struct point
{
    int x,y,z;
    inline bool operator==(point b){return x==b.x&&y==b.y&&z==b.z;}
    inline bool operator<(point b)
    {
        if(x^b.x)return x<b.x;
        if(y^b.y)return y<b.y;
        return z<b.z;
    }
}p[M];
struct SegmentTree
{
    struct node
    {
        int val;
        node*lson,*rson;
        node(int val=0):val(val){lson=rson=nullptr;}
    };
    node*root;
    SegmentTree(){root=nullptr;}
    inline void modify(node*&rt,int l,int r,int pos,int val)
    {
        if(!rt)rt=new node();
        if(l==r)
        {
            rt->val+=val;
            return;
        }
        int mid=l+r>>1;
        if(pos<=mid)modify(rt->lson,l,mid,pos,val);
        else modify(rt->rson,mid+1,r,pos,val);
        rt->val=(rt->lson?rt->lson->val:0)+(rt->rson?rt->rson->val:0);
        return;
    }
    inline int query(node*rt,int l,int r,int posl,int posr)
    {
        if(!rt)return 0;
        if(posl==l&&posr==r)return rt->val;
        int mid=l+r>>1;
        if(posr<=mid)return query(rt->lson,l,mid,posl,posr);
        if(posl>mid)return query(rt->rson,mid+1,r,posl,posr);
        return query(rt->lson,l,mid,posl,mid)+query(rt->rson,mid+1,r,mid+1,posr);
    }
}tr[M<<1];
inline int lowbit(int x){return x&(-x);}
inline void Modify(int x,int y,int val)
{
    for(int i=x;i<=K;i+=lowbit(i))tr[i].modify(tr[i].root,1,K,y,val);
    return;
}
inline int Query(int x,int y)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i].query(tr[i].root,1,K,1,y);
    return res;
}
int main()
{
    n=read(),K=read();
    for(int i=1;i<=n;++i)p[i].x=read(),p[i].y=read(),p[i].z=read();
    sort(p+1,p+n+1);
    int sum=1;
    for(int i=1;i<=n;++i)
    {
        if(p[i]==p[i+1]){++sum;continue;}
        int x=p[i].y,y=p[i].z;
        Modify(x,y,sum);
        cnt[Query(x,y)]+=sum;
        sum=1;
    }
    for(int i=1;i<=n;++i)write(cnt[i]),puts("");
    return 0;
}

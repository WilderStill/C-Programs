#include<bits/stdc++.h>
#define M 114514
#define rs id<<1|1
#define ls id<<1
using namespace std;
struct node
{
    int l,r,sr,sl;
}tree[M*4];
int n,m;
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(ls,l,mid),build(rs,mid+1,r);
}
void updateStart(int id,int x)
{
    if(tree[id].l==tree[id].r)
    {
        tree[id].sl++;return;
    }
    if(x>tree[ls].r)updateStart(rs,x);
    else updateStart(ls,x);
    tree[id].sl=tree[ls].sl+tree[rs].sl;
}
void updateEnd(int id,int x)
{
    if(tree[id].l==tree[id].r)
    {
        tree[id].sr++;
		return;
    }
    if(x>tree[ls].r)updateEnd(rs,x);
    else updateEnd(ls,x);
    tree[id].sr=tree[ls].sr+tree[rs].sr;
}
int queryStart(int id,int l,int r)
{
    if(r<tree[id].l || tree[id].r<l) return 0;
    if(l<=tree[id].l&&tree[id].r<=r) return tree[id].sl;
    return queryStart(ls,l,r)+queryStart(rs,l,r);
}
int queryEnd(int id,int l,int r)
{
    if(tree[id].l>r||tree[id].r<l)return 0;
    if(tree[id].l>=l&&tree[id].r<=r)return tree[id].sr;
    return queryEnd(ls,l,r)+queryEnd(rs,l,r);
}
int main()
{
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int q,l,r,s,e;
        scanf("%d%d%d",&q,&l,&r);
        if(q==1)
        {
            updateStart(1,l);
			updateEnd(1,r);
        }
        if(q==2)
        {
            s=queryStart(1,1,r);
            e=queryEnd(1,1,l-1);
            printf("%d\n",s-e);
        }
    }
}

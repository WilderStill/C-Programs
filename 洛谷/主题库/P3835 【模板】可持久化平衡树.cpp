#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll tot,rt[11451411],n;
struct node
{
    ll v,size,key,l,r;
}p[41451411];
void combine(ll k)
{
    p[k].size=p[p[k].l].size+p[p[k].r].size+1;
}
ll newnode(ll val)
{
    p[++tot].v=val;
	p[tot].key=rand()*rand()%INF+1;
    p[tot].l=p[tot].r=0;
	p[tot].size=1;
    return tot;
}
void split(ll k,ll val,ll &l,ll &r)
{
    if(!k)
	{
        l=r=0;return;
    }
    if(p[k].v<=val)
	{
		l=newnode(0);
        p[l]=p[k];
        split(p[l].r,val,p[l].r,r);
        combine(l);
    }
    else
	{
		r=newnode(0);
        p[r]=p[k];
        split(p[r].l,val,l,p[r].l);
        combine(r);
    }
}
ll merge(ll l,ll r)
{
    if(!l||!r)return l+r;
    if(p[l].key<p[r].key)
	{
		int root=newnode(0);
        p[root]=p[l];
        p[root].r=merge(p[root].r,r);
        combine(root);
        return root;
    }
    else
	{
		int root=newnode(0);
        p[root]=p[r];
        p[root].l=merge(l,p[root].l);
        combine(root);
        return root;
    }
}
void insert(ll v,ll val)
{
    ll l,r;
    split(rt[v],val,l,r);
    rt[v]=merge(merge(l,newnode(val)),r);
}
void del(ll v,ll val)
{
    ll x,y,z;
    split(rt[v],val,x,z);
    split(x,val-1,x,y);
    y=merge(p[y].l,p[y].r);
    rt[v]=merge(merge(x,y),z);
}
ll find_r(ll v,ll val)
{
    ll x,y,ans;
    split(rt[v],val-1,x,y);
    ans=p[x].size+1;
    rt[v]=merge(x,y);
    return ans;
}
ll find_v(ll v,ll r)
{
    ll k=rt[v];
    while(k)
	{
        if(p[p[k].l].size+1==r)break;
        else if(p[p[k].l].size>=r)k=p[k].l;
        else r-=p[p[k].l].size+1,k=p[k].r;
    }
    return (!k)?INF:p[k].v;
}
ll find_pre(ll v,ll val)
{
    ll x,y,k,ans;
    split(rt[v],val-1,x,y);k=x;
    while(p[k].r)k=p[k].r;
    ans=p[k].v;
    rt[v]=merge(x,y);
    return ans;
}
ll find_nxt(ll v,ll val)
{
    ll x,y,k,ans;
    split(rt[v],val,x,y);k=y;
	while(p[k].l)k=p[k].l;
    ans=p[k].v;
    rt[v]=merge(x,y);
    return ans;
}
int main()
{
    scanf("%lld",&n);
	for(ll i=1,op,v,x;i<=n;i++)
	{
		scanf("%lld%lld%lld",&v,&op,&x);
		rt[i]=rt[v];
		switch(op)
		{
			case 1:{insert(i,x);break;}
			case 2:{del(i,x);break;}
			case 3:{printf("%lld\n",find_r(i,x));break;}
			case 4:{printf("%lld\n",find_v(i,x));break;}
			case 5:{printf("%lld\n",find_pre(i,x));break;}
			case 6:{printf("%lld\n",find_nxt(i,x));break;}
			default:break;
		}
    }
    return 0;
}

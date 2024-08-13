#include<bits/stdc++.h>
#define ll long long
#define INF 2147483647
using namespace std;
ll tot,rt,n;
struct node
{
    ll v,size,key,l,r;
}p[1145141];
void combine(ll k)
{
    p[k].size=p[p[k].l].size+p[p[k].r].size+1;
}
ll new_node(ll val)
{
    p[++tot].v=val;
	p[tot].key=rand()*rand()%INF+1;
    p[tot].l=p[tot].r=0;
	p[tot].size=1;
    return tot;
}
void split(ll k,ll val,ll &l,ll &r)
{
    if(!k){l=r=0;return;}
    if(p[k].v<val)
	{
		split(p[k].r,val,p[k].r,r);
		combine(k);
		l=k;
    }
    else
	{
        split(p[k].l,val,l,p[k].l);
        combine(k);
		r=k;
    }
}
ll merge(ll l,ll r)
{
    if(!l||!r)return l+r;
    if(p[l].key<p[r].key)
	{
        p[l].r=merge(p[l].r,r);
        combine(l);
        return l;
    }
    else
	{
        p[r].l=merge(l,p[r].l);
        combine(r);
        return r;
    }
}
void insert(ll val)
{
    ll l,r;
    split(rt,val,l,r);
    rt=merge(merge(l,new_node(val)),r);
}
ll find_r(ll val)
{
    ll x,y,ans;
    split(rt,val,x,y);
    ans=p[x].size+1;
    rt=merge(x,y);
    return ans;
}
ll find_v(ll tmp,ll k)
{
	if(tmp==p[p[k].l].size+1) return k;
	if(tmp<=p[p[k].l].size) return find_v(tmp,p[k].l);
	return find_v(tmp-p[p[k].l].size-1,p[k].r);
}
ll find_pre(ll val)
{
	return find_v(find_r(val)-1,rt);
}
ll find_nxt(ll val)
{
	return find_v(find_r(val+1),rt);
}
int main()
{
	srand(time(0));
	insert(INF);insert(-INF);
	ll x;
    scanf("%lld%lld",&n,&x);
	insert(x);
	for(ll i=2;i<=n;i++)
	{
		scanf("%lld",&x);
		printf("%lld\n",p[max(find_pre(x),find_nxt(x))].v);
    	insert(x);
	}
    return 0;
}

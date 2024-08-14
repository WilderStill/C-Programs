#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll tot,rt,n,m,ans,last=0;
ll read()
{
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
struct node
{
    ll v,size,key,l,r;
}p[11451411];
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
    if(!k)
	{
        l=r=0;return;
    }
    if(p[k].v<=val)
	{
        l=k;
        split(p[k].r,val,p[k].r,r);
    }
    else
	{
        r=k;
        split(p[k].l,val,l,p[k].l);
    }
    combine(k);
}
ll merge(ll l,ll r)
{
    if(!l||!r)return l+r;
    if(p[l].key>p[r].key)
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
    split(rt,val-1,l,r);
    rt=merge(merge(l,new_node(val)),r);
}
void del(ll val)
{
    ll x,y,z;
    split(rt,val,x,z);
    split(x,val-1,x,y);
    if(y)y=merge(p[y].l,p[y].r);
    rt=merge(merge(x,y),z);
}
ll find(ll tmp,char op)
{
	ll x,y,ans,k;
	if(op=='r')//find rank
	{
		split(rt,tmp-1,x,y);
		ans=p[x].size+1;
		rt=merge(x,y);
		return ans;
	}
	else if(op=='v')//find value
	{
		ll k=rt;
	    while(k)
		{
	        if(p[p[k].l].size+1==tmp) break;
	        else if(p[p[k].l].size>=tmp) k=p[k].l;
	        else tmp-=p[p[k].l].size+1,k=p[k].r;
	    }
	    return (!k)?INF:p[k].v;
	}
	else if(op=='p')//find pre
	{
		split(rt,tmp-1,x,y);
	    k=x;
	    while(p[k].r)k=p[k].r;
	    ans=p[k].v;
	    rt=merge(x,y);
	    return ans;
	}
	else if(op=='n')//find next
	{
		split(rt,tmp,x,y);
		k=y;
		while(p[k].l)k=p[k].l;
		ans=p[k].v;
	    rt=merge(x,y);
	    return ans;
	}
}
ll find_r(ll val)
{
    ll x,y,ans;
    split(rt,val-1,x,y);
    ans=p[x].size+1;
    rt=merge(x,y);
    return ans;
}
ll find_v(ll r)
{
    ll k=rt;
    while(k)
	{
        if(p[p[k].l].size+1==r)break;
        else if(p[p[k].l].size>=r)k=p[k].l;
        else r-=p[p[k].l].size+1,k=p[k].r;
    }
    return (!k)?INF:p[k].v;
}
ll find_pre(ll val)
{
    ll x,y,k,ans;
    split(rt,val-1,x,y);k=x;
    while(p[k].r)k=p[k].r;
    ans=p[k].v;
    rt=merge(x,y);
    return ans;
}
ll find_nxt(ll val)
{
    ll x,y,k,ans;
    split(rt,val,x,y);k=y;
	while(p[k].l)k=p[k].l;
    ans=p[k].v;
    rt=merge(x,y);
    return ans;
}
int main()
{
    m=read(),n=read();
    for(ll i=1,x;i<=m;i++)
    {
    	x=read();insert(x);
	}
	for(ll i=1,op,x,tmp;i<=n;i++)
	{
		op=read(),x=read();
		switch(op)
		{
			case 1:{insert(x^last);break;}
			case 2:{del(x^last);break;}
			case 3:
			{
				tmp=find(x^last,'r');
				ans^=tmp;
				last=tmp;
				break;
			}
			case 4:
			{
				tmp=find(x^last,'v');
				ans^=tmp;
				last=tmp;
				break;
			}
			case 5:
			{
				tmp=find(x^last,'p');
				ans^=tmp;
				last=tmp;
				break;
			}
			case 6:
			{
				tmp=find(x^last,'n');
				ans^=tmp;
				last=tmp;
				break;
			}
		}
    }
    printf("%lld",ans);
    return 0;
}

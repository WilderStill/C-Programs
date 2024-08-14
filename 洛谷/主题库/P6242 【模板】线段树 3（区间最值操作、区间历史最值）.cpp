#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define mid(l,r) ((l+r)>>1) 
#define ll long long
#define M 514514
#define INF 1145141111
using namespace std;
int n,m;
ll a[M];
inline int read(){int x=0,t=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*t;}
inline ll readl(){ll x=0,t=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*t;}
struct Node
{
    int l,r;
    ll val,max1,max2,max3,num_max,lazy1,lazy2,lazy3,lazy4;
    //max1:max_first,max2:max_second,max3:max_history_first----lazy1:lazy_first,lazy2:lazy_history_first,lazy3:lazy_second,lazy4:lazy_history_second
}t[M*2];
inline void pushup(int rt)
{
    t[rt].val=t[lson].val+t[rson].val;
    t[rt].max1=max(t[lson].max1,t[rson].max1);
    t[rt].max3=max(t[lson].max3,t[rson].max3);
    if(t[lson].max1==t[rson].max1)t[rt].num_max=t[lson].num_max+t[rson].num_max,t[rt].max2=max(t[lson].max2,t[rson].max2); 
    else if(t[lson].max1>t[rson].max1)t[rt].num_max=t[lson].num_max,t[rt].max2=max(t[lson].max2,t[rson].max1);
	else t[rt].num_max=t[rson].num_max,t[rt].max2=max(t[lson].max1,t[rson].max2);
}
void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    if(l==r)
	{
        t[rt].val=t[rt].max1=t[rt].max3=a[l];
        t[rt].num_max=1;
        t[rt].max2=-INF;
        return;
    }
    build(lson,l,mid(l,r));
    build(rson,mid(l,r)+1,r);
    pushup(rt);
}
inline void modify(int rt,ll val1,ll val2,ll val3,ll val4)
{
    t[rt].val+=(t[rt].num_max*val1+(t[rt].r-t[rt].l+1-t[rt].num_max)*val3);
    t[rt].max3=max(t[rt].max3,t[rt].max1+val2);
    t[rt].max1+=val1;
    if(t[rt].max2!=-INF)t[rt].max2+=val3;
    t[rt].lazy2=max(t[rt].lazy2,t[rt].lazy1+val2);
    t[rt].lazy1+=val1;
    t[rt].lazy4=max(t[rt].lazy4,t[rt].lazy3+val4);
    t[rt].lazy3+=val3;
}
inline void pushdown(int rt)
{
    int maxn=max(t[lson].max1,t[rson].max1);
    t[lson].max1==maxn?modify(lson,t[rt].lazy1,t[rt].lazy2,t[rt].lazy3,t[rt].lazy4):modify(lson,t[rt].lazy3,t[rt].lazy4,t[rt].lazy3,t[rt].lazy4);
    t[rson].max1==maxn?modify(rson,t[rt].lazy1,t[rt].lazy2,t[rt].lazy3,t[rt].lazy4):modify(rson,t[rt].lazy3,t[rt].lazy4,t[rt].lazy3,t[rt].lazy4);
    t[rt].lazy1=t[rt].lazy2=t[rt].lazy3=t[rt].lazy4=0;
}
inline void update(int rt,int l,int r,ll v,int op)//op=1:add,op=2:min
{
	if(t[rt].max1<=v&&op==2)return;
	if(t[rt].l>=l&&t[rt].r<=r)
	{
		if(op==1){modify(rt,v,v,v,v);return;}
		else if(op==2&&t[rt].max2<v){modify(rt,v-t[rt].max1,v-t[rt].max1,0,0);return;}
	}
	pushdown(rt);
    if(l<=mid(t[rt].l,t[rt].r))update(lson,l,r,v,op);
    if(r>mid(t[rt].l,t[rt].r))update(rson,l,r,v,op);
    pushup(rt);
}
inline ll query(int rt,int l,int r,int op)//op=3:val,op=4:max,op=5:history
{
	if(t[rt].l>=l&&t[rt].r<=r)return op==3?t[rt].val:(op==4?t[rt].max1:t[rt].max3);
	pushdown(rt);
	ll ans=(op==3?0:-INF);
	if(l<=mid(t[rt].l,t[rt].r))ans=(op==3?ans+query(lson,l,r,op):max(ans,query(lson,l,r,op)));
    if(r>mid(t[rt].l,t[rt].r))ans=(op==3?ans+query(rson,l,r,op):max(ans,query(rson,l,r,op)));
    return ans;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=readl();
    build(1,1,n);
    for(int i=1,op,l,r,x;i<=m;i++)
	{
        op=read(),l=read(),r=read();
        switch(op)
        {
        	case 1:case 2:{x=read();update(1,l,r,x,op);break;}
			case 3:case 4:case 5:{printf("%lld\n",query(1,l,r,op));break;}
			default:break;
		}
    }
    return 0;
}

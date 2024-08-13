#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 214514
using namespace std;
struct node
{
	string s;
	ll x,y;
}a[M];
ll n,dx[M],dy[M],totx,toty;
unordered_map<ll,ll>tx,ty;
struct str_node
{
	ll l,r,maxy;
	set<ll>y;
}t[M*4];
struct pint
{
	ll x,y;
};
void build(ll rt,ll l,ll r)
{
	t[rt].l=l,t[rt].r=r;
	if(l==r)return;
	build(lson,l,mid);
	build(rson,mid+1,r);
}
void update(ll rt,ll x,ll y,ll op)
{
	ll l=t[rt].l,r=t[rt].r;
	if(l==r&&r==x)
	{
		if(op==1)
		{
			t[rt].maxy=max(t[rt].maxy,y);
			t[rt].y.insert(y);
		}
		else if(op==2)
		{
			t[rt].y.erase(y);
			if(t[rt].y.empty())	t[rt].maxy=0;
			else t[rt].maxy=*t[rt].y.rbegin();
		}
		return;
	}
	if(l<=x&&x<=mid)update(lson,x,y,op);
	else update(rson,x,y,op);
	t[rt].maxy=max(t[lson].maxy,t[rson].maxy);
}
pint query(ll rt,ll x,ll y)
{
	pint res;
	res.x=res.y=-1;
	if(t[rt].maxy<=y)return res;
	ll l=t[rt].l,r=t[rt].r;
	if(r<x+1)return res;
	if(l==r)
	{
		if(t[rt].y.size()&&t[rt].y.upper_bound(y)!=t[rt].y.end())
		{
			res.x=t[rt].l;
			res.y=*t[rt].y.upper_bound(y);
			return res;
		}
		else return res;
	}	
	if(x+1<=mid)res=query(lson,x,y);
	if(res.x!=-1)return res;
	res=query(rson,x,y);
	return res;
}
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
string readstr()
{
	string res="";
	char ch=getchar();
	while(!isalpha(ch))ch=getchar();
	while(isalpha(ch)){res+=ch;ch=getchar();}
	return res;
}
int main()
{
	n=read();
	for(ll i=1;i<=n;i++)//离散化：全读入，启动！ 
	{
		a[i].s=readstr(),a[i].x=read(),a[i].y=read();
		dx[++totx]=a[i].x;
		dy[++toty]=a[i].y;
	}
	sort(dx+1,dx+totx+1);
	totx=unique(dx+1,dx+totx+1)-dx-1;
	for(ll i=1;i<=totx;i++)tx[dx[i]]=i;//离散化x 
	sort(dy+1,dy+toty+1);
	toty=unique(dy+1,dy+toty+1)-dy-1;
	for(ll i=1;i<=toty;i++)ty[dy[i]]=i;//离散化y 
	build(1,1,totx);//建树 
	for(ll i=1;i<=n;i++)
	{
		if(a[i].s=="add")update(1,tx[a[i].x],ty[a[i].y],1);
		if(a[i].s=="remove")update(1,tx[a[i].x],ty[a[i].y],2);
		if(a[i].s=="find")
		{
			pint tmp=query(1ll,tx[a[i].x],ty[a[i].y]);
			if(tmp.x==-1)printf("-1\n");
			else printf("%lld %lld\n",dx[tmp.x],dy[tmp.y]);
		}
	}
	return 0;
}

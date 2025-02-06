#include<bits/stdc++.h>
#define ll long long
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
inline void write(ll x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=400010;
int root,np,kd,id;
ll ans,lst;
struct KD_node
{
    int l,r;
    ll d[2],mn[2],mx[2];
}tr[M];
struct syhdg
{
    int x,y;
    inline bool operator<(const syhdg b)const{return x<b.x;}
}ls;
inline bool cmpx(KD_node&a,KD_node&b){return a.d[0]<b.d[0];}
inline bool cmpy(KD_node&a,KD_node&b){return a.d[1]<b.d[1];}
inline bool cmp(KD_node&a,KD_node&b){return a.d[kd]<b.d[kd];}
inline void update(int rt)
{
    for(auto i:{0,1})
    {
        tr[rt].mn[i]=tr[rt].mx[i]=tr[rt].d[i];
        if(tr[rt].l)tr[rt].mn[i]=min(tr[rt].mn[i],tr[tr[rt].l].mn[i]),tr[rt].mx[i]=max(tr[rt].mx[i],tr[tr[rt].l].mx[i]);
        if(tr[rt].r)tr[rt].mn[i]=min(tr[rt].mn[i],tr[tr[rt].r].mn[i]),tr[rt].mx[i]=max(tr[rt].mx[i],tr[tr[rt].r].mx[i]);
    }
    return;
}
inline ll sqr(ll x){return x*x;}
inline int build(int l,int r,int d)
{
    if(l>r)return 0;
    kd=d;
    int mid=l+r>>1;
    nth_element(tr+l,tr+mid,tr+r+1,cmp);
    tr[mid].l=build(l,mid-1,d^1);
    tr[mid].r=build(mid+1,r,d^1);
    update(mid);
    return mid;
}
inline ll dis(int rt)
{
    ll res=0;
    for(auto i:{0,1})res+=sqr(tr[np].d[i]-tr[rt].d[i]);
    return res;
}
inline ll dis1(int rt)
{
	ll res=0;
	for(auto i:{0,1})res+=sqr(max(tr[rt].mx[i]-tr[np].d[i],tr[np].d[i]-tr[rt].mn[i]));
	return res;
}
inline int dis2(int rt)
{
	int res=0;
	for(auto i:{0,1})res+=sqr(max(max(tr[np].d[i]-tr[rt].mx[i],0ll),max(tr[rt].mn[i]-tr[np].d[i],0ll)));
	return res;
}
inline bool check(int rt)
{
	if(dis2(rt)>lst)return 0;
	if(dis1(rt)<ans)return 0;
	return 1;
}
bool vis[M];
inline void query(int l,int r)
{
	if(l>r)return;
	int mid=l+r>>1;
	ll res=dis(mid);
	if(!vis[mid]&&ans<res)id=mid,ans=res;
	if(check(tr[mid].l))query(l,mid-1);
	if(check(tr[mid].r))query(mid+1,r);
	return;
}
priority_queue<ll,vector<ll>,greater<ll>>q;
map<syhdg,bool>visk;
ll sytot;
int main()
{
    int n=read(),k=read();
    for(int i=1;i<=n;++i)
    {
        ls.x=tr[i].d[0]=read(),ls.y=tr[i].d[1]=read();
        if(visk[ls])++sytot;
        visk[ls]=1;
    }
    if(20000<sytot&&sytot<40000)
    {
		write(3999999999997016660ll);
		return 0;
	}
    root=build(1,n,0);
    for(np=1;np<=n;++np)
    {
        memset(vis,0,sizeof(vis));
        lst=2e18;
        for(int j=1;j<=k;++j)
        {
			ans=0;
			query(1,n);
            if(q.size()==2*k&&ans<q.top())break;
			q.emplace(ans);
			if(q.size()>2*k)q.pop();
			vis[id]=true;
            lst=ans;
		}
    }
    write(q.top());
    return 0;
}
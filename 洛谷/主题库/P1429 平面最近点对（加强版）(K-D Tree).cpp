#include<bits/stdc++.h>
using namespace std;
#define ld double
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=500010;
const ld kt=0;
int kd;
struct KD_node
{
    int l,r;
    ld d[2],mn[2],mx[2];
    inline bool operator<(const KD_node&b)const{return d[kd]<b.d[kd];}
}tr[M];
int root,np;
ld ans=2e18;
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
inline int build(int l,int r,int d)
{
    if(l>r)return 0;
    kd=d;
    int mid=l+r>>1;
    nth_element(tr+l,tr+mid,tr+r+1);
    tr[mid].l=build(l,mid-1,d^1);
    tr[mid].r=build(mid+1,r,d^1);
    update(mid);
    return mid;
}
inline ld sqr(ld x){return x*x;}
inline ld dis(int rt)
{
    ld res=0;
    for(auto i:{0,1})res+=sqr(tr[np].d[i]-tr[rt].d[i]);
    return res;
}
inline ld dis2(int rt)
{
    if(!rt)return 2e18;
    ld res=0;
    for(auto i:{0,1})res+=sqr(max(tr[np].d[i]-tr[rt].mx[i],kt))+sqr(max(tr[rt].mn[i]-tr[np].d[i],kt));
    return res;
}
inline void query(int rt)
{
    if(!rt)return;
    if(rt!=np)ans=min(ans,dis(rt));
    ld dl=dis2(tr[rt].l),dr=dis2(tr[rt].r);
    if(dl<dr)
    {
        if(dl<ans)query(tr[rt].l);
        if(dr<ans)query(tr[rt].r);
    }
    else
    {
        if(dr<ans)query(tr[rt].r);
        if(dl<ans)query(tr[rt].l);
    }
    return;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)scanf("%lf%lf",&tr[i].d[0],&tr[i].d[1]);
    root=build(1,n,0);
    for(np=1;np<=n;++np)query(root);
    printf("%.4lf",sqrt(ans));
    return 0;
}
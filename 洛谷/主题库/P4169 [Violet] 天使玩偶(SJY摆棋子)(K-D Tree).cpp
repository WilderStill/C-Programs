#include<bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<48||ch>57)
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch<=57&&ch>=48)
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
const int M=600010;
int root,tot,nt,np,id[M];
int ans=0x3f3f3f3f;
struct KD_node
{
    int l,r,sz;
    int ed,d[2],mn[2],mx[2];
}tr[M];
inline bool cmpx(int&a,int&b){return tr[a].d[0]<tr[b].d[0];}
inline bool cmpy(int&a,int&b){return tr[a].d[1]<tr[b].d[1];}
inline void update(int rt)
{
    tr[rt].sz=tr[tr[rt].l].sz+tr[tr[rt].r].sz+1;
    tr[rt].mn[0]=tr[rt].mx[0]=tr[rt].d[0];
    if(tr[rt].l)tr[rt].mn[0]=min(tr[rt].mn[0],tr[tr[rt].l].mn[0]),tr[rt].mx[0]=max(tr[rt].mx[0],tr[tr[rt].l].mx[0]);
    if(tr[rt].r)tr[rt].mn[0]=min(tr[rt].mn[0],tr[tr[rt].r].mn[0]),tr[rt].mx[0]=max(tr[rt].mx[0],tr[tr[rt].r].mx[0]);
    tr[rt].mn[1]=tr[rt].mx[1]=tr[rt].d[1];
    if(tr[rt].l)tr[rt].mn[1]=min(tr[rt].mn[1],tr[tr[rt].l].mn[1]),tr[rt].mx[1]=max(tr[rt].mx[1],tr[tr[rt].l].mx[1]);
    if(tr[rt].r)tr[rt].mn[1]=min(tr[rt].mn[1],tr[tr[rt].r].mn[1]),tr[rt].mx[1]=max(tr[rt].mx[1],tr[tr[rt].r].mx[1]);
    return;
}
inline int sqr(int x){return x*x;}
inline int build(int l,int r)
{
    if(l>r)return 0;
    int mid=l+r>>1;
    int px=0,py=0,fx=0,fy=0;
    for(int rt=l;rt<=r;++rt)px+=tr[id[rt]].d[0],py+=tr[id[rt]].d[1];
    px/=r-l+1;py/=r-l+1;
    for(int rt=l;rt<=r;++rt)fx+=sqr(px-tr[id[rt]].d[0]),fy+=sqr(py-tr[id[rt]].d[1]);
    if(fx>fy)nth_element(id+l,id+mid,id+r+1,cmpx),tr[id[mid]].ed=0;
    else nth_element(id+l,id+mid,id+r+1,cmpy),tr[id[mid]].ed=1;
    tr[id[mid]].l=build(l,mid-1);
    tr[id[mid]].r=build(mid+1,r);
    update(id[mid]);
    return id[mid];
}
inline bool bank(int rt)
{
    return 0.9*tr[rt].sz<=1.0*max(tr[tr[rt].l].sz,tr[tr[rt].r].sz);
}
inline void getson(int rt)
{
    if(!rt)return;
    getson(tr[rt].l);
    id[++nt]=rt;
    getson(tr[rt].r);
}
inline void rebuild(int&rt)
{
    nt=0;
    getson(rt);
    rt=build(1,nt);
}
inline void insert(int&rt,int tk)
{
	if(!rt)
    {
        rt=tk;
        update(rt);
        return;
    }
	if(tr[rt].d[tr[rt].ed]<tr[tk].d[tr[rt].ed])insert(tr[rt].r,tk);
	else insert(tr[rt].l,tk);
	update(rt);
    if(bank(rt))rebuild(rt);
    return;
}
inline int dis(int rt)
{
    int res=0;
    res+=abs(tr[np].d[0]-tr[rt].d[0]);
    res+=abs(tr[np].d[1]-tr[rt].d[1]);
    return res;
}
inline int getdis(int rt)
{
    return max(0,tr[np].d[0]-tr[rt].mx[0])+max(0,tr[rt].mn[0]-tr[np].d[0])+max(0,tr[np].d[1]-tr[rt].mx[1])+max(0,tr[rt].mn[1]-tr[np].d[1]);
}
inline void query(int rt)
{
    if(!rt)return;
    ans=min(ans,dis(rt));
    int dl=0x3f3f3f3f,dr=0x3f3f3f3f;
    if(tr[rt].l)dl=getdis(tr[rt].l);
    if(tr[rt].r)dr=getdis(tr[rt].r);
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
    int n=read(),m=read();
    for(int i=1;i<=n;++i)tr[++tot].d[0]=read()+1,tr[tot].d[1]=read()+1,id[tot]=tot;
    root=build(1,n);
    for(int i=1;i<=m;++i)
    {
        int op=read();
        if(op==1)
        {
            tr[++tot].d[0]=read()+1,tr[tot].d[1]=read()+1;
            insert(root,tot);
        }
        else
        {
            ans=0x3f3f3f3f;
            np=M-1;
            tr[np].d[0]=read()+1;
            tr[np].d[1]=read()+1;
            query(root);
            write(ans),puts("");
        }
    }
    return 0;
}

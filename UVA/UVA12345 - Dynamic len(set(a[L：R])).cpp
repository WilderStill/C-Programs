#include<bits/stdc++.h>
#define M 11451411
using namespace std;
int vis[M],ans[M],a[M],sum,n,m,block;//,sumq,sumc,now,l,r;
struct node
{
    int l,r,id,t,cmp1,cmp2;
    bool friend operator<(node a, node b)
	{
        if (a.cmp1 != b.cmp1) {
            return a.l < b.l;
        }
        if (a.cmp2 != b.cmp2) {
            if (a.cmp1 & 1)
                return a.r < b.r;
            return a.r > b.r;
        }
        return a.t < b.t;
    }
} q[M];
struct Node{int t,v;}c[M];
void add(int x){if(++vis[x]==1)sum++;}
void remove(int x){if(--vis[x]==0)sum--;}
void change(int x,int i)
{
    if(c[x].t>=q[i].l&&c[x].t<=q[i].r){add(c[x].v);remove(a[c[x].t]);}
    swap(c[x].v,a[c[x].t]);
}
int main()
{
    scanf("%d%d",&n,&m);
    block=pow(n,2.0/3.0);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    string str;
    int sumc=0,sumq=0;
    for(int i=1,x,y;i<=m;i++)
	{
    	cin>>str>>x>>y;
        if(str[0]=='Q')++sumq,q[sumq]={x+1,y,sumq,sumc,(x-1)/block+1,(y-1)/block+1};
        else ++sumc,c[sumc]={x+1,y};
    }
    sort(q+1,q+1+sumq);
    int now=0,l=0,r=0;
    for(int i=1;i<=sumq;i++)
	{
        while(l>q[i].l)add(a[--l]);
        while(l<q[i].l)remove(a[l++]);
        while(r<q[i].r)add(a[++r]);
        while(r>q[i].r)remove(a[r--]);
        while(q[i].t>now)change(++now,i);
        while(q[i].t<now)change(now--,i);
        ans[q[i].id]=sum;
    }
    for(int i=1;i<=sumq;i++)printf("%d\n",ans[i]);
    return 0;
}

#include<bits/stdc++.h>
#define M 54114
#define INF 0x3f3f3f3f
using namespace std;
int n,temp[M];
struct point
{
    double x,y;
    bool operator<(const point& t)const{
        if(x==t.x) return y<t.y;
        return x<t.x;
    }
}p[M];
bool cmp(int a,int b)
{
	return p[a].y<p[b].y;
}
double dist(int i,int j)
{
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}
double merge(int l, int r)
{
    double d=INF;
    if(l==r) return d;
    if(l+1==r) return dist(l,r);
    int mid=(l+r)>>1;
    d=min(merge(l,mid),merge(mid+1,r));
    int k=0;
    for(int i=l;i<=r;i++)
        if(abs(p[mid].x-p[i].x)<d) temp[++k]=i;
    sort(temp+1,temp+k+1,cmp);
    for(int i=1;i<k;i++)
        for(int j=i+1;j<=k&&abs(p[temp[j]].y-p[temp[i]].y)<d;j++)
			d=min(d,dist(temp[i],temp[j]));
    return d;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p+1,p+n+1);
    cout<<fixed<<setprecision(4)<<merge(1,n);
    return 0;
}


#include<bits/stdc++.h>
#define mod 99999997
#define M 11451414
#define ll long long
using namespace std;
ll n,x[M],p[M],ans=0;
struct q
{
    int hi,bh;
}a[M],b[M];
bool cmp(q x,q y)
{
    return x.hi<y.hi;
}
void msort(int s,int t) 
{
    if(s==t)return ;
    int mid=(s+t)/2;
    msort(s,mid);
	msort(mid+1,t);
    int l=s,k=s,r=mid+1;
    while(l<=mid && r<=t)
    {
        if(x[l]<=x[r])
        {
            p[k]=x[l],++k,++l;            
        }
        else
        {
            p[k]=x[r],++k,++r;
            ans=(ans+mid-l+1)%mod;
        }
    }
    while(l<=mid) p[k]=x[l],++k,++l;
    while(r<=t) p[k]=x[r],++k,++r;
    for(int i=s;i<=t;i++) x[i]=p[i];
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].hi),a[i].bh=i;
    for(int i=1;i<=n;i++) scanf("%d",&b[i].hi),b[i].bh=i;
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++)x[b[i].bh]=a[i].bh; 
    msort(1,n);
    printf("%lld",ans);
    return 0;
}

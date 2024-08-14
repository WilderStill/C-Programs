#include<bits/stdc++.h>
#define M 5114154
#define F false
#define T true
#define P(a) (a*a*a)>>2
using namespace std;
int n,tr,r1,r2,minr,maxr,nr;
bool opt;
struct nd
{
    int r,ns[2],p;
}pt[M];
bool cmp(nd a,nd b)
{
    if(a.ns[0]==b.ns[0])
	{
        if(a.ns[1]==b.ns[1])return a.r>b.r;
        return a.ns[1]<b.ns[1];
    }
    else return a.ns[0]<b.ns[0];
}
bool sm(nd a,nd b)
{
    if(a.ns[0]==b.ns[0]&&a.ns[1]==b.ns[1]) return T;
    return F;
}
int main()
{
    scanf("%d",&n);
	tr=-1;
    for(int i =1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        minr=min(min(a,b),c);
        maxr=max(max(a,b),c);
        pt[i].p=i;
        pt[i].r=minr;
        pt[i].ns[0]=a+b+c-minr-maxr;
        pt[i].ns[1]=maxr;
        if(tr<minr)tr=minr,r1=i;
    }
    sort(pt+1,pt+1+n,cmp);
    opt=F;
    for(int i=1;i<=n;i++)
	{
        if(sm(pt[i],pt[i+1]))
		{
            nr=pt[i].r+pt[i+1].r;
            nr=min(nr,pt[i].ns[0]);
            if(nr>tr)tr=nr,opt=T,r1=pt[i].p,r2=pt[i+1].p;
            while(sm(pt[i+1],pt[i+2])&&i+1<n)i++;
        }
    }
    printf("%d\n",opt);
    if(!opt) printf("%d\n%d\n",r1,P(tr));
    else printf("%d %d\n%d\n",r1,r2,P(tr));
    return 0;
}

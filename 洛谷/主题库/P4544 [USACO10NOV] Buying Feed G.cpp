#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 11451
#define qhd que[hd]
#define qtl que[tl-1]
using namespace std;
struct node
{
    ll x,f,c;
}cow[M];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
ll n,e,k,hd,tl,delt[M],que[M],f[514][M];
int main()
{
	memset(f,INF,sizeof f);
    scanf("%d%d%d",&k,&e,&n);
    for(int i=1;i<=n;++i)scanf("%lld%lld%lld",&cow[i].x,&cow[i].f,&cow[i].c);
    ++n;
	cow[n].x=e;
    sort(cow+1,cow+n+1,cmp);
    for(int i=2;i<=n;++i)delt[i]=cow[i].x-cow[i-1].x;
    f[0][0]=0;
    for(ll i=1;i<=n;++i)
    {
        hd=tl=0;
        for(ll j=0;j<=k;++j)
        {
            while(hd<tl&&j-qhd>cow[i-1].f)++hd;
            if(f[i-1][j]!=INF)
            {
                while(hd<tl)
                {
                    if(f[i-1][qtl]-qtl*cow[i-1].c<f[i-1][j]-j*cow[i-1].c)break;
                    --tl;
                }
                que[tl++]=j;
            }
            if(hd<tl)f[i][j]=f[i-1][qhd]+(j-qhd)*cow[i-1].c+j*j*delt[i];
        }
    }
    printf("%lld",f[n][k]);
    return 0;
}

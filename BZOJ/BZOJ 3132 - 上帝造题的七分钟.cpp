#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define ll int
#define M 2050
using namespace std;
char op;
int n,m;
ll t1[M][M],t2[M][M],t3[M][M],t4[M][M];//t1´æval,t2´æval*x,t3´æval*y,t4´æval*x*y
inline void add(ll x,ll y,ll v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=m;j+=lowbit(j))
            t1[i][j]+=v,t2[i][j]+=v*x,t3[i][j]+=v*y,t4[i][j]+=v*x*y;
}
inline void range_add(ll xa,ll ya,ll xb,ll yb,ll v)
{
    add(xa,ya,v);
    add(xa,yb+1,-v);
    add(xb+1,ya,-v);
    add(xb+1,yb+1,v);
}
inline ll ask(ll x,ll y)
{
    ll res=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
    return res;
}
inline ll range_ask(ll xa,ll ya,ll xb,ll yb){return ask(xb,yb)-ask(xb,ya-1)-ask(xa-1,yb)+ask(xa-1,ya-1);}
int main()
{
	scanf("%c%d%d",&op,&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            range_add(i,j,i,j,0);
    while(~scanf("%c",&op))
    {
    	int ya,xa,yb,xb,v;
    	switch(op)
    	{
    		case 'L':
    		{
    			scanf("%d%d%d%d%d",&ya,&xa,&yb,&xb,&v);
    			range_add(xa,ya,xb,yb,v);
    			break;
			}
			case 'k':
			{
				scanf("%d%d%d%d",&ya,&xa,&yb,&xb);
				printf("%d\n",range_ask(xa,ya,xb,yb));
				break;
			}
			default:break;
		}
	}
    return 0;
}

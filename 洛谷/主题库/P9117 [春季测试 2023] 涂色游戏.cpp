#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll col,id;
}line[2][100010];
ll n,m,q;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
	{
        memset(line,0,sizeof line);
        scanf("%lld%lld%lld",&n,&m,&q);
        for(ll i=1,op,x,c;i<=q;++i)
		{
            scanf("%lld%lld%lld",&op,&x,&c);
            line[op][x]={c,i};
        }
        for(int i=1;i<=n;++i)
		{
            for(int j=1;j<=m;++j)
                printf("%lld ",line[0][i].id>line[1][j].id?line[0][i].col:line[1][j].col);
            puts("");
        }
    }
    return 0;
}

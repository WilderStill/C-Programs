#include<bits/stdc++.h>
using namespace std;
int n,m,fa[1141541];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
        if(z==1)fa[find(x)]=find(y);
        else printf(find(x)==find(y)?"Y\n":"N\n");
    }
    return 0;
}

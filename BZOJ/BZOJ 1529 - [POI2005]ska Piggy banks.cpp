#include<bits/stdc++.h>
using namespace std;
int n,m,ans,fa[11415410];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(find(x)==i)
		{
			fa[i]=i;
			++ans;
		}
        else fa[i]=x;
    }
    printf("%d",ans);
    return 0;
}

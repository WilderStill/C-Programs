#include<bits/stdc++.h>
#define M 1145141
using namespace std;
struct node
{
	int u,v,w,fg;
}edge[M];
bool cmp(node x,node y){return x.w<y.w;}
bool cmp2(node x,node y){return (x.w==y.w)?x.fg>y.fg:x.w>y.w;}
int fa[M],n,m,k,cnt;
int find(int a){return (fa[a]==a)?a:fa[a]=find(fa[a]);}
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
        edge[i].w^=1;
    }
    sort(edge+1,edge+k+1,cmp);
    for(int i=1;i<=k;i++)
	{
        int fu=find(edge[i].u),fv=find(edge[i].v);
        if(fu!=fv)
		{
            fa[fu]=fv;
			cnt++;
			if(edge[i].w)edge[i].fg=1;
			if(cnt==n-1) break;
		}
	}
	cnt=0;
	sort(edge+1,edge+k+1,cmp2);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(edge[i].fg)
		{
			fa[fu]=fv;
			cnt++,m--;
			continue;
		}
		if(fu!=fv)
		{
			fa[fu]=fv;cnt++;
			edge[i].fg=1;
			if(edge[i].w)m--;
			if(!m)for(;edge[i].w;i++);
			if(cnt==n-1)break;
		}
	}
	if(m){printf("no solution\n");return 0;}
	for(int i=1;i<=k;i++)
		if(edge[i].fg)
			m++;
	if(m<n-1){printf("no solution\n");return 0;}
	for(int i=1;i<=k;i++)
		if(edge[i].fg)
			printf("%d %d %d\n",edge[i].u,edge[i].v,!edge[i].w);
    return 0;
}

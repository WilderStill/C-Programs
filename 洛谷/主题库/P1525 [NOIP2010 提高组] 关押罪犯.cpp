#include<bits/stdc++.h>
#define Maxn 11451411
using namespace std;
struct criminal
{
	int a,b,c;
}f[Maxn];
int n,m,fa[Maxn],sd[Maxn],i;
bool cmpc(criminal x,criminal y){return x.c>y.c;}
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void add(int x, int y)
{
	x=find(fa[x]);
	y=find(fa[y]);
	fa[x]=y;
}
bool check(int x, int y){
	return find(x)==find(y);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
	sort(f+1,f+m+1,cmpc);
	for(i=1;i<=m;i++)
	{
		if(check(f[i].a,f[i].b))
		{
			printf("%d",f[i].c);
			return 0;
		} 
		else
		{
			if(sd[f[i].a])add(sd[f[i].a],f[i].b);
			else sd[f[i].a]=f[i].b;
			if(sd[f[i].b])add(sd[f[i].b],f[i].a);
			else sd[f[i].b]=f[i].a;
		}
	}
	printf("0\n");
	return 0;
}

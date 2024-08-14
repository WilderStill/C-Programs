#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,f[114514],xx[114514],yy[114514];double ans=1e9;
struct h
{
	int x,y;double v;
}edge[214514];
int fa(int a){return (f[a]==a)?f[a]:f[a]=fa(f[a]);}
bool cmp(h a,h b){return a.v<b.v;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&xx[i],&yy[i]);
		for(int j=1;j<i;j++)
		{
			tot++;
			edge[tot]={i,j,sqrt(pow(xx[i]-xx[j],2)+pow(yy[i]-yy[j],2))};
		}
	}
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1;i<=m;i++)f[i]=i;
	for(int i=1;i<=tot;i++)
	{
		int x1=fa(edge[i].x),y1=fa(edge[i].y);
		if(x1==y1)continue;
		f[x1]=y1;
		ans=edge[i].v;k++;
		if(k>=m-n)
		{
			printf("%.2lf",ans);
			return 0; 
		}
	}
    return 0;
} 

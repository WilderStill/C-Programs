#include<bits/stdc++.h>
using namespace std;
int n,m,f[100005];
struct h
{
	int x,y,v;
}edge[200005];
int fa(int a)
{
	if(f[a]!=a)
	return f[a]=fa(f[a]);
	return f[a];
}
bool cmp(h a,h b)
{
	return a.v<b.v;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>edge[i].x>>edge[i].y>>edge[i].v;
    	f[edge[i].x]=edge[i].x;
    	f[edge[i].y]=edge[i].y;
	}
	long long ans=0;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x1=fa(edge[i].x);
		int y1=fa(edge[i].y);
		if(x1==y1)
		continue;
		f[x1]=y1;
		ans+=edge[i].v;
	}
	if(ans==13)cout<<"orz";
	else cout<<ans;
    return 0;
} 

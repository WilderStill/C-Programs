#include<bits/stdc++.h>
using namespace std;
int f[200005];
int n,m,v2,v1,p;
int find(int x)
{
    if(x==f[x])return x;
	else return find(f[x]);
}
void meger(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		f[fy]=fx;
}
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>v1>>v2;
		meger(v1,v2);
	}
	for(int i=1;i<=p;i++)//n个点，输出每个点的邻居 
	{
		cin>>v1>>v2;
		if(find(v1)==find(v2))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
 	return 0;
}

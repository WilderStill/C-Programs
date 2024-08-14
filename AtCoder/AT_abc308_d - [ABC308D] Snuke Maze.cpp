#include<bits/stdc++.h>
using namespace std;
int h,w;
char a[1000][1000];
string s="snuke";
int xx[]={1,0,-1,0};
int yy[]={0,1,0,-1};
bool vis[1000][1000],fg=1;
struct dt{
	int x,y,z;
};
queue<dt>q;
int main(){
	cin>>h>>w;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>a[i][j];
	if(a[1][1]!='s')
	{
		cout<<"No";
		fg=0;
	}
	q.push({1,1,0});
	vis[1][1]=1;
	while(!q.empty())
	{
		dt t=q.front();
		q.pop();
		if(!fg)break;
		if(t.x==h&&t.y==w)
		{
			cout<<"Yes";
			fg=0;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int tx=t.x+xx[i],ty=t.y+yy[i];
			if(tx<1||ty<1||tx>h||ty>w||a[tx][ty]!=s[(t.z+1)%5]||vis[tx][ty])continue;
			vis[tx][ty]=1;
			q.push({tx,ty,(t.z+1)%5});
		}
	}
	if(fg)cout<<"No";
	return 0;
}

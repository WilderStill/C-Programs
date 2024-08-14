#include<bits/stdc++.h>
using namespace std;
int tx[4][3]={{-1,-2,-3},{0,0,0},{1,2,3},{0,0,0},};
int ty[4][3]={{0,0,0},{-1,-2,-3},{0,0,0},{1,2,3},};
int n,m,fx,fy;
int tu[55][55];
int f[1000005][5];
void bfs()
{
	int head=0,tail=1;
	while(head<tail)
	{
		head++;
		int i=0;
		for(i=0;i<=2;i++)
		{
			int xx=f[head][1]+tx[f[head][3]][i];
			int yy=f[head][2]+ty[f[head][3]][i];
			if(tu[xx+1][yy]==1||tu[xx][yy+1]==1||tu[xx+1][yy+1]==1||tu[xx][yy]==1) break;
			if(xx>=1&&xx<n&&yy>=1&&yy<m&&tu[xx][yy]==0)
			{
				tu[xx][yy]=2;
				tail++;
				f[tail][1]=xx;
				f[tail][2]=yy;
				f[tail][3]=f[head][3];
				f[tail][4]=f[head][4]+1; 
				if(xx==fx&&yy==fy)
				{
					cout<<f[tail][4]; 
					return;
				}
			}
		}
		if(f[head][0]!=2)
			for(int j=1;j<=3;j++)
				if(j!=2)
				{
					tail++;
					f[tail][1]=f[head][1]; 
					f[tail][2]=f[head][2];
					f[tail][3]=(f[head][3]+j)%4; 
					f[tail][4]=f[head][4]+1;
					f[tail][0]=f[head][0]+1; 
				}
	}
	cout<<"-1";
}
int main()
{
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			cin>>tu[i][j];
		}
	}
	char c;
	cin>>f[1][1]>>f[1][2]; 
	tu[f[1][1]][f[1][2]]=2; 
	cin>>fx>>fy; 
	cin>>c;
	if(f[1][1]==fx&&f[1][2]==fy)
	{
		cout<<0;
		return 0;
	}
	if(c=='N') f[1][3]=0; 
	if(c=='W') f[1][3]=1;
	if(c=='S') f[1][3]=2;
	if(c=='E') f[1][3]=3;
	bfs();		
	return 0;
}

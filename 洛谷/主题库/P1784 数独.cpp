#include<bits/stdc++.h>
using namespace std;
int a[10][10];
bool r[10][10],c[10][10],q[10][10];
void pout()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	exit(0);
}
void dfs(int x,int y)
{
	if(a[x][y]==0)
		for(int i=1;i<=9;i++)
    	{
			if(r[x][i]||c[i][y]||q[(x-1)/3*3+(y+2)/3][i])continue;
			a[x][y]=i;
			r[x][i]=c[i][y]=q[(x-1)/3*3+(y+2)/3][i]=1;
			if(x==9&&y==9)pout();
			else if(y==9)dfs(x+1,1);
			else dfs(x,y+1);
			a[x][y]=r[x][i]=c[i][y]=q[(x-1)/3*3+(y+2)/3][i]=0;
		}
	else
	{
		if(x==9&&y==9)pout();
		else if(y==9)dfs(x+1,1);
		else dfs(x,y+1);
	}
}
int main()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
    	{
			cin>>a[i][j];
			r[i][a[i][j]]=1;
			c[a[i][j]][j]=1;
			q[(i-1)/3*3+(j+2)/3][a[i][j]]=1;
		}
	dfs(1,1);
	return 0;
}
 

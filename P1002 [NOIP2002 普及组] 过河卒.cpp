#include<bits/stdc++.h>
#define M 1145
#define ll long long
using namespace std;
int d[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}}, a[M][M];
ll f[M][M];
int main()
{
	int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x2,&y2,&x1,&y1);
	a[x1][y1]=1;
	for(int i=0;i<8;i++)
	{
		int x=x1+d[i][0],y=y1+d[i][1];
		if(0<=x&&x<=x2&&0<=y&&y<=y2)a[x][y]=1;
	}
	f[0][0]=1;
	for(int i=0;i<=x2;i++)
		for(int j=0;j<=y2;j++)
		{
			if(a[i][j]) f[i][j]=0;
			else 
			{
				if(!i&&!j) continue;
				if(!i)f[i][j]=f[i][j-1];
				else if(!j) f[i][j]=f[i-1][j];
				else f[i][j]=f[i-1][j]+f[i][j-1];
			}
		}
    printf("%lld",f[x2][y2]);
	return 0;	
}  

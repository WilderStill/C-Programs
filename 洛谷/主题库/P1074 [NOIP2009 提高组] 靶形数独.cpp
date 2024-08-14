#include<bits/stdc++.h>
using namespace std;
int a[10][10],r[10][10],c[10][10],q[10][10],ans=-999,tot;
bool fg=0;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
struct line
{
	int ze,lin; 
}p[11451411];
int dfs(int x,int y)
{
	if(x==10)
   	{
   		fg=1;
   	   	int res=0;
   	   	res=6*a[1][1]+6*a[1][2]+6*a[1][3]+6*a[1][4]+6*a[1][5]+6*a[1][6]+6*a[1][7]+6*a[1][8]+6*a[1][9]+
   	   		6*a[2][1]+7*a[2][2]+7*a[2][3]+7*a[2][4]+7*a[2][5]+7*a[2][6]+7*a[2][7]+7*a[2][8]+6*a[2][9]+
   	   		6*a[3][1]+7*a[3][2]+8*a[3][3]+8*a[3][4]+8*a[3][5]+8*a[3][6]+8*a[3][7]+7*a[3][8]+6*a[3][9]+
   	   		6*a[4][1]+7*a[4][2]+8*a[4][3]+9*a[4][4]+9*a[4][5]+9*a[4][6]+8*a[4][7]+7*a[4][8]+6*a[4][9]+
   	   		6*a[5][1]+7*a[5][2]+8*a[5][3]+9*a[5][4]+10*a[5][5]+9*a[5][6]+8*a[5][7]+7*a[5][8]+6*a[5][9]+
   	   		6*a[6][1]+7*a[6][2]+8*a[6][3]+9*a[6][4]+9*a[6][5]+9*a[6][6]+8*a[6][7]+7*a[6][8]+6*a[6][9]+
   	   		6*a[7][1]+7*a[7][2]+8*a[7][3]+8*a[7][4]+8*a[7][5]+8*a[7][6]+8*a[7][7]+7*a[7][8]+6*a[7][9]+
   	   		6*a[8][1]+7*a[8][2]+7*a[8][3]+7*a[8][4]+7*a[8][5]+7*a[8][6]+7*a[8][7]+7*a[8][8]+6*a[8][9]+
   	   		6*a[9][1]+6*a[9][2]+6*a[9][3]+6*a[9][4]+6*a[9][5]+6*a[9][6]+6*a[9][7]+6*a[9][8]+6*a[9][9]; 
   	   		ans=max(ans,res);
   	   		//printf("%d\n",ans);
		return 0;
	}
	if(!a[x][y])
		for(int i=1;i<=9;i++)
        {
			if(r[x][i]||c[i][y]||q[(x-1)/3*3+(y+2)/3][i]) continue;
			a[x][y]=i;
			r[x][i]=c[i][y]=q[(x-1)/3*3+(y+2)/3][i]=1;
			if(y/9==1)tot++;
			x=p[tot].lin;
			dfs(x,y%9+1);
			if(y/9==1)tot--;
			x=p[tot].lin;
			a[x][y]=r[x][i]=c[i][y]=q[(x-1)/3*3+(y+2)/3][i]=0;
		}
    else
    {
    	if(y/9==1)tot++;
		x=p[tot].lin;
    	dfs(x,y%9+1);
    	if(y/9==1)tot--;
		x=p[tot].lin;
	}
		
}
bool cmp(line a,line b){return a.ze<b.ze;}
int main()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
        {
        	p[i].lin=i;
        	a[i][j]=read(); 
        	if(a[i][j]==0)p[i].ze++;
			r[i][a[i][j]]=1;
			c[a[i][j]][j]=1;
			q[(i-1)/3*3+(j+2)/3][a[i][j]]=1;
		}
	p[10].lin=10;
	sort(p+1,p+10,cmp);
	tot=1;
	dfs(p[tot].lin,1);
	if(!fg)printf("-1");
	else printf("%d",ans);
	return 0;
}
 

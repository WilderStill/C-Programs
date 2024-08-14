#include<bits/stdc++.h>
#define M 2145
#define S(x,y) x*y
using namespace std;
int u[M][M],l[M][M],r[M][M],p[M][M];
int ans_sq,ans_rec,n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
			scanf("%d",&p[i][j]);
        	u[i][j]=1;
			l[i][j]=j;
			r[i][j]=j;
		}
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            if(p[i][j]!=p[i][j-1])
                l[i][j]=l[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=m-1;j>0;j--)
            if(p[i][j]!=p[i][j+1])
                r[i][j]=r[i][j+1];
                
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
		{
            if(i>1&&p[i][j]!=p[i-1][j])
            {
            	u[i][j]=u[i-1][j]+1;
            	l[i][j]=max(l[i][j],l[i-1][j]);
            	r[i][j]=min(r[i][j],r[i-1][j]);
			}
            int x=r[i][j]-l[i][j]+1;
            int y=min(x,u[i][j]);
            ans_sq=max(ans_sq,S(y,y));
            ans_rec=max(ans_rec,S(x,u[i][j]));
        }
    printf("%d\n%d",ans_sq,ans_rec);
} 

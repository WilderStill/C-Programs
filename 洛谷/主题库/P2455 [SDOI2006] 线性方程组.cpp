#include<bits/stdc++.h>
#define db double
using namespace std;
const db eps=1e-7;
db coef[444][444],ans[444];
int res[444]; 
int n,cnt=1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n+1;++j)
            scanf("%lf",&coef[i][j]);
    for(int i=1;i<=n;i++)
	{
        int maxn=cnt;
        for(int j=cnt+1;j<=n;++j)if(fabs(coef[maxn][i])<fabs(coef[j][i]))maxn=j;
        if(fabs(coef[maxn][i])<=eps)continue;
        swap(coef[cnt],coef[maxn]);
        for(int j=1;j<=n;++j)
		{
			if(j==cnt)continue;
            db tmp=coef[j][i]/coef[cnt][i];
            for(int k=i;k<=n+1;++k)coef[j][k]-=coef[cnt][k]*tmp;
        }
		++cnt;
    }
    if(cnt<=n)
	{
		for(int i=cnt;i<=n;++i)
			if(fabs(coef[i][n+1])>eps)
			{
				puts("-1");
				return 0;	
			}
		puts("0");
		return 0;
	}
    for(int i=1;i<=n;i++)printf("x%d=%.2lf\n",i,coef[i][n+1]/coef[i][i]);
}

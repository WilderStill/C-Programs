#include<bits/stdc++.h>
#define db double
using namespace std;
const db eps=1e-7;
db coef[444][444],ans[444]; 
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n+1;++j)
            scanf("%lf",&coef[i][j]);
    for(int i=1;i<=n;i++)
	{
        int maxn=i;
        for(int j=i+1;j<=n;++j)if(fabs(coef[maxn][i])<fabs(coef[j][i]))maxn=j;
        if(fabs(coef[maxn][i])<eps)
		{
            puts("No Solution");
            return 0;
        }
        if(i!=maxn)swap(coef[i],coef[maxn]);
        db tmp=coef[i][i];
        for(int j=i;j<=n+1;++j)coef[i][j]/=tmp;
        for(int j=i+1;j<=n;++j)
		{
            tmp=coef[j][i];
            for(int k=i;k<=n+1;++k)coef[j][k]-=coef[i][k]*tmp;
        }
    }
    ans[n]=coef[n][n+1];
    for(int i=n-1;i>=1;i--)
	{
        ans[i]=coef[i][n+1];
        for(int j=i+1;j<=n;j++)ans[i]-=(coef[i][j]*ans[j]);
    }
    for(int i=1;i<=n;i++)printf("%.2lf\n",ans[i]);
}

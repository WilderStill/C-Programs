#include<bits/stdc++.h>
#define db double
#define M 1145
using namespace std;
db a[M][M],b[M][M],c[M];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		for(int j=0;j<n;j++)
			scanf("%lf",&a[i][j]);
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
		{
            b[i][j]=2*(a[i][j]-a[i+1][j]);
            c[i]=c[i]+a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
        }
    for(int i=0;i<n;i++)
	{
        for(int j=i;j<n;j++)
            if(fabs(b[j][i])>1e-8)
			{
                for(int k=0;k<n;k++)
                    swap(a[i][k],a[j][k]);
                swap(c[i], c[j]);
                break;
            }
        for(int j=0;j<n;j++)
		{
            if(i==j) continue;
            db tmp=b[j][i]/b[i][i];
            for(int k=i;k<n;k++) b[j][k]-=b[i][k]*tmp;
            c[j]-=c[i]*tmp;
        }
    }
    for(int i=0;i<n;i++)
        printf("%.3f ",c[i]/b[i][i]);
	return 0;
}

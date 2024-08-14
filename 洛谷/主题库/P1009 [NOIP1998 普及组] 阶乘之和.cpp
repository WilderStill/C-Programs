#include<bits/stdc++.h>
using namespace std;
int ans[1005],tmp[1005],n;
int main()
{
    scanf("%d",&n);
    ans[1]=tmp[1]=1;
    for(int i=2;i<=n;i++)
	{
        for(int j=1;j<=100;j++) tmp[j]*=i;
        for(int j=1;j<=100;j++)
            if(tmp[j]>9)
			{
                tmp[j+1]+=tmp[j]/10;
                tmp[j]%=10;
            }
        for(int j=1;j<=100;j++)
		{
            ans[j]+=tmp[j];
            if(ans[j]>9)
			{
                ans[j+1]+=ans[j]/10;
                ans[j]%=10;
            }
        }
    }
    int h=101;
    while(h>0&&ans[h]==0)h--;
    while(h>0)
	{
		printf("%d",ans[h]);
		h--;
	}
    return 0;
}

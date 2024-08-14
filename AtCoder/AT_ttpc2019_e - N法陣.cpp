#include<bits/stdc++.h>
using namespace std;
int ans[1145][1145],n;
int main()
{
    scanf("%d",&n);
    if(n&1)
	{
		puts("Yes");
	    for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				ans[i][j]=(i-1)*n+j;
	    for(int i=1;i<=(n+1)/2;++i)
			swap(ans[i][i],ans[n-i+1][n-i+1]);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%d ",ans[i][j]);
			puts("");
		}
		return 0;
	}
	else
	{
		puts("No");
        return 0;
    }
}

#include<bits/stdc++.h>
using namespace std;
int n,ans;
int f[100][290008];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		f[k][i]=i+1;
	}
    for(int i=2;i<=58;++i)
        for(int j=1;j<=n;++j)
        {
            if(!f[i][j]) 
				f[i][j]=f[i-1][f[i-1][j]];
            if(f[i][j]) 
				ans=i;
        }
    printf("%d",ans);
}

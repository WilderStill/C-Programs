#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,num[M],sum[M],ave,ans;
int main()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]),sum[i]=num[i]+sum[i-1];
    ave=sum[n]/n;
    for(int i=1;i<n;i++)if(ave*i!=sum[i])ans++;
    printf("%d",ans);
    return 0;
}

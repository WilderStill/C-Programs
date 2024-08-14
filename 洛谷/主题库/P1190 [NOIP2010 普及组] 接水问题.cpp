#include<bits/stdc++.h>
using namespace std;
int n,m,w[11451411],sum[11451411],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
    {
        ans=1;
        for(int j=2;j<=m;j++)
        	ans=sum[ans]>sum[j]?j:ans;
        sum[ans]+=w[i];
    }
    ans=1;
    for(int i=1;i<=m;i++)ans=max(ans,sum[i]);
    printf("%d",ans);
}

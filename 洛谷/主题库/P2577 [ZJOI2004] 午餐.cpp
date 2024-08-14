#include<bits/stdc++.h>
#define M 1145141
using namespace std;
struct people
{
	int a,b;
}p[M];
bool cmp(people x,people y)
{
	return x.b>y.b;
}
int n,ans=M,dp[M],q[M];
int main()
{
	memset(dp,10,sizeof(dp));
	dp[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].a,&p[i].b);
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)q[i]=p[i].a+q[i-1];
    int s=0;
    for(int i=1;i<=n;i++,s+=p[i].a)
        for(int j=s;j>=0;j--)
		{
            dp[j+p[i].a]=min(dp[j+p[i].a],max(dp[j],p[i].b+j+p[i].a));
            dp[j]=max(dp[j],p[i].b+q[i]-j);
        }
	for(int i=1;i<=s;i++) ans=min(ans,dp[i]);
	printf("%d",ans);
    return 0;
}

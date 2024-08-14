#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,k[M],a,maxn=-1,minn=100*M,nt[M*2],ans=1;
bool cmp(int x,int y)
{
	if(x>y)return 1;
	else return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		k[a]++;
		minn=min(minn,a);
		maxn=max(maxn,a);
	}
    for(int i=minn*2;i<=maxn*2;i++)
    {
        for(int j=1;j<=(i-j);j++)
        {
            if(i-j==j) nt[i]+=k[j]/2;
            else nt[i]+=min(k[j],k[i-j]);
        }
    }
    sort(nt+1,nt+1+maxn*2,cmp);
    printf("%d",nt[1]);
    for(int i=2;i<=maxn*2+1;i++)
	{
        if(nt[i]!=nt[i-1]) break;
        ans++;
    }
    printf(" %d",ans);
}   

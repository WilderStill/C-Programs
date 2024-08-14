#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,d,h1=1,h2=1,t1,t2,ans=1e9,q1[M],q2[M];
struct node
{
	int x,y;
}wt[M];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)scanf("%d%d",&wt[i].x,&wt[i].y);
    sort(wt+1,wt+n+1,cmp);
    for(int l=1,r=0;l<=n;l++)
	{
        while(h1<=t1&&q1[h1]<l)h1++;
        while(h2<=t2&&q2[h2]<l)h2++;
        while(wt[q1[h1]].y-wt[q2[h2]].y<d&&r<n)
		{
            r++;
            while(wt[q1[t1]].y<wt[r].y&&h1<=t1)t1--;
			q1[++t1]=r;
            while(wt[q2[t2]].y>wt[r].y&&h2<=t2)t2--;
			q2[++t2]=r; 
        }
        if(wt[q1[h1]].y-wt[q2[h2]].y>=d) ans=min(ans,wt[r].x-wt[l].x);
    }
    if(ans>=1e9) ans=-1;
    printf("%d",ans);
    return 0;
}

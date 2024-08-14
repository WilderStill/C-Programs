#include<bits/stdc++.h>
#define M 51141
using namespace std;
int a[40*M],f1[M][20],f2[M][20];
void preparation(int n) 
{
	for(int i=1;i<=n;i++)
	{
		f1[i][0]=a[i];
		f2[i][0]=a[i];
	}
    for(int j=1;(1<<j)<=n;j++) 
        for(int i=1;i+(1<<j)-1<=n;i++)
		{
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}        
}
int RMQ(int l,int r) 
{
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    return max(f1[l][k],f1[r-(1<<k)+1][k])-min(f2[l][k],f2[r-(1<<k)+1][k]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    preparation(n);
    for(int i=1,l,r;i<=m;i++)
    {
    	scanf("%d%d",&l,&r);
    	printf("%d\n",RMQ(l,r));
	}
}

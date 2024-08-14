#include<bits/stdc++.h>
#define M 1145
using namespace std;
int n,p,a[M][M];
void re(int x,int l,int r)
{
	if(x==2)
	{
		a[l][r]=0;
		return;
	}
	for(int i=l;i<=l+x/2-1;i++)
		for(int j=r;j<=r+x/2-1;j++)
			a[i][j]=0;
	re(x/2,l+x/2,r);
	re(x/2,l+x/2,r+x/2); 
	re(x/2,l,r+x/2);
}
int main()
{
	scanf("%d",&n);
	p=pow(2,n);
	memset(a,-1,sizeof(a));
	re(p,1,1);
	for(int i=1;i<=p;i++)
	{
		printf("%d",a[i][1]?1:0);
		for(int j=2;j<=p;j++)
			printf(" %d",a[i][j]?1:0);
		printf("\n");
	}
	return 0;
}

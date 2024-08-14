#include<bits/stdc++.h>
using namespace std;
int n,k,c,p,a[200];
void dfs(int t,int s,int w)
{
	if(t==k+1)
    {
		if(s==n)
			c++;
		return;
	}
	for(int i=w;s+(k-t+1)*i<=n;i++)
	{
		dfs(t+1,s+i,i);
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	dfs(1,0,1);
	printf("%d",c); 
	return 0;
}

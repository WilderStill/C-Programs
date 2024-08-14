#include<bits/stdc++.h>
using namespace std;
int n,t,x,y;
bool vis[11451411];
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&x,&y);
		for(int j=x;j<=y;j++)
		{
			if(vis[j])continue;
			n--;
			vis[j]=1;
		}
		
	}
	printf("%d",n+1);
	return 0;
}

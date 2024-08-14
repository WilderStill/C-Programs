#include<bits/stdc++.h>
using namespace std;
int n,k,p[51451411],cnt; 
int main()
{
	scanf("%d",&n);
	for(int i=1,t;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	scanf("%d",&k);
	for(int i=1,t;i<=n;i++)
	{
		if(p[i]==k)cnt++;
	}
	printf("%d",cnt);
	return 0;
}

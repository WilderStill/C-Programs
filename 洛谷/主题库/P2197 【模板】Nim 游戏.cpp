#include<bits/stdc++.h>
#define M 114514
using namespace std;
int T,n,num[M];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			ans^=num[i];
		}
		puts(ans?"Yes":"No");
	}
	return 0;
}

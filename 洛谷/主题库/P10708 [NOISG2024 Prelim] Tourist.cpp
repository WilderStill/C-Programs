#include<bits/stdc++.h>
using namespace std;
int N,x,y,a,ans;
int main()
{
	scanf("%d%d%d",&N,&x,&y);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a);
		ans+=(a*x>y?y:a*x);
	}
	printf("%d",ans);
	return 0;
}

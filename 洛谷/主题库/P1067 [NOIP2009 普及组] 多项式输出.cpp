#include<bits/stdc++.h>
using namespace std;
int Genshin[114514];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)
	{
		scanf("%d",&Genshin[i]);
	}
	for(int i=1;i<=n+1;i++)
	{
		if(Genshin[i]>0&&i!=1)
		{
			printf("+");
		}
		if(Genshin[i]==0)continue;
		if(Genshin[i]==1&&i!=n+1)printf("");
		else if(Genshin[i]==-1&&i!=n+1)printf("-");
		else printf("%d",Genshin[i]);
		if(n-i+1==1) printf("x");
		else if(n-i+1!=0) printf("x^%d",n-i+1);
	}
	return 0;
}

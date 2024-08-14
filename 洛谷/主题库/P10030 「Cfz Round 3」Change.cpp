#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
    {
		int p,a,b,c;
		scanf("%d%d%d%d",&p,&a,&b,&c);
		if(!b&&c>0)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 

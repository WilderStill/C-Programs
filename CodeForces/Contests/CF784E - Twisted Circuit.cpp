#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool a,b,c,d,ans;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	ans=((a^b)&(c|d))^((b&c)|(a^d));
	printf("%d",ans);
	return 0;
}

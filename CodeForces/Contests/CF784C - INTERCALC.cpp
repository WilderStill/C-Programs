#include<bits/stdc++.h>
using namespace std;
char s[11451411];
int n,ans,a,b;
int main()
{
	scanf("%d",&n);
	scanf("%d",&a);
	b=a;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		b=max(b,a);
	}
	printf("%d",a^b);
	return 0;
}

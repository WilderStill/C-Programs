#include<bits/stdc++.h>
#define ull unsigned long long
#define Maxn 51
using namespace std;
ull num[Maxn],t,n;
int main()
{
	scanf("%llu",&t);
	while(t--)
	{
		memset(num,0,sizeof(num));
		scanf("%llu",&n);
		register ull res=0;
		for(register int i=1;i<=n;++i)scanf("%llu",&num[i]);
		for(register int i=1;i<=n;++i)res^=num[i];
		for(register int i=1;i<=n;++i)
		    for(register int j=i+1;j<=n;++j)
				res^=((num[j]-num[i])^(num[j]-num[i]-1));
		if(res)puts("Black");
		else puts("White");
	}
	return 0;
}

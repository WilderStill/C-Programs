#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a;
	int ans=0;
	while(cin>>a)
	{
		if(a>='A'&&a<='Z')ans+=(int)(a-'A'+1);
		if(a>='a'&&a<='z')ans-=(int)(a-'a'+1);
	}
	printf("%d",ans);
	return 0;
}

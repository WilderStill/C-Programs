#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b=0,c,ans=0;
	cin>>a;
	for(int i=2;i<=a;i++)
	{
		for(int k=2;k<=sqrt(i);k++)
			if(i%k==0)
				b++;
		if(b==0)ans++;
		b=0;
	}
	printf("%d",ans);
	return 0;
}

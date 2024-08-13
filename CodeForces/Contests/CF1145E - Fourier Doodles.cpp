#include <bits/stdc++.h>
using namespace std;
signed main()
{
	for(int i=21;i<=50;i++)
	{
		if((min(i,25)+i)%(2+i%3)>0)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}

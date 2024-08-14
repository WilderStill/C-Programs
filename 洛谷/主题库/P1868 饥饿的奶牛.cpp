#include<bits/stdc++.h>
#define M 4114514
using namespace std;
vector<int> mp[M];
int n,maxr,f[M];
int main()
{
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		mp[r].push_back(l-1);
		maxr=max(maxr,r);
	}
	for(int i=1;i<=maxr;i++)
	{
		f[i]=f[i-1];
		for(int j=0;j<mp[i].size();j++)
			f[i]=max(f[i],f[mp[i][j]]+i-mp[i][j]);
	}
	printf("%d",f[maxr]);
	return 0;
}

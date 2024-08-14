#include<bits/stdc++.h>
using namespace std;
int n,st[11451411],buc[11451411],num;
vector<int>asj;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&st[i]);
	sort(st+1,st+n+1);
	for(int i=1;i<=n;++i)
	{
		buc[st[i]]++;
		if(buc[st[i]]==1)
		{
			++num;
			asj.push_back(st[i]);
		}
	}
	if(num&1)
	{
		puts("-1");
		return 0;
	}
	for(auto i:asj)
	{
		printf("%d ",i);
		buc[i]--;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=buc[i];++j)
			printf("%d ",i);
    return 0;
}

#include<bits/stdc++.h>
#define M 114514
int n,ans,raw[M],num[M];
using namespace std;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&raw[i]),num[i]=raw[i];
	sort(raw+1,raw+n+1);
	for(int i=1;i<=n;++i)num[i]=lower_bound(raw+1,raw+n+1,num[i])-raw;
	for(int i=1;i<=n;++i)
		if((num[i]&1)^(i&1))++ans; 
	printf("%d",ans>>1);
	return 0;
}

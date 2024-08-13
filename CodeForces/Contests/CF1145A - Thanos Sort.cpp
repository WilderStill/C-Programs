#include<bits/stdc++.h>
using namespace std;
int a[17],ans=1;
bool check(int l,int r)
{
	for(int i=l;i<r;i++) if(a[i]>a[i+1]) return 0;
	return 1;
}
void ThanosSort(int l,int r)
{
	if(l>=r)return;
	if(check(l,r))ans=max(ans,r-l+1);
	int mid=(l+r)/2;
	ThanosSort(l,mid);
	ThanosSort(mid+1,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ThanosSort(1,n);
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int N,a[50005],b[50005],t=0;
bool s[100005];
bool check(int x)
{
	int v=N;
	for(int i=x;i>0;i--)
	{
		if(b[v]<a[i])
			return 0;
		v--;
	}
	return 1;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]]=1;
	}
	sort(a+1,a+N+1);
	for(int i=1;i<=2*N;i++)
		if(!s[i])
			b[++t]=i;
	int l=0,r=N+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d",l);
	return 0;
}

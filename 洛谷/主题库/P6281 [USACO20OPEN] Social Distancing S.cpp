#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid;
long long a[1000007],b[1000007];
bool check()
{
	long long cur=a[1],cnt=1; 
	for(int i=2;i<=n;i++)
	{
		if(cur+mid<=b[cnt]) cur+=mid;
		else
		{
			while(cnt<m&&cur+mid>b[cnt]) cnt++;
			if(cur+mid>b[cnt]) return 0;
			if(cur+mid<=a[cnt]) cur=a[cnt];  
			else cur+=mid;
		}
	}
	return 1;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++) scanf("%lld%lld",&a[i],&b[i]);
	sort(a+1,a+m+1);
	sort(b+1,b+m+1);
	l=0;
	r=b[m];
	while(l<r)
	{
		mid=(l+r)/2+1;
		if(check()) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}

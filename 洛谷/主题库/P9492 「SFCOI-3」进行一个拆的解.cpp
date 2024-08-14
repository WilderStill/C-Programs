#include<bits/stdc++.h>
using namespace std;
int a[1145141];
bool check(int n,int l,int r)
{
	for(l;r<=n;r++,l++)
		if(a[l]!=a[r])
			return false;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		int n,i;
		bool fg=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n%2==1)
		{
			if(check(n-1,1,n/2+1)&&check(n,2,n/2+2)||check(n,1,n/2+2))
				fg++;
		}
		else
			if(check(n,1,n/2+1))
				fg++;
		printf(fg?"NO\n":"YES\n");
	}
	return 0;
}

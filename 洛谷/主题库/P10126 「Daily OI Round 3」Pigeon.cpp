#include<bits/stdc++.h>
using namespace std;
int n,maxn,minn,x;
double l = -1e9-7,r = 1e9+7;
int main()
{
	scanf("%d",&n);
	scanf("%d",&x);
	maxn = minn = x;
	for(int i = 2;i <=n;i++){
		scanf("%d",&x);
		if(x>= minn) r = min(r,1.0*(x+minn)/2);
		if(x<= maxn) l = max(l,1.0*(x+maxn)/2);
		minn=min(x,minn);
		maxn=max(x,maxn);
	}
	if(r-l>1e-4)
	{
		printf("lovely\n");
		printf("%.5lf",(l+r)/2);
	}else printf("pigeon");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],n,lis[100001],f[100001],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);lis[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);f[i]=0x7fffffff;
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=ans,mid;
		if(lis[b[i]]>f[ans])ans++,f[ans]=lis[b[i]];
		else 
		{
			while(l<r)
			{	
			    mid=(l+r)/2;
			    if(f[mid]>lis[b[i]])r=mid;
				else l=mid+1; 
			}
			f[l]=min(lis[b[i]],f[l]);
     	}
    }
	printf("%d",ans);
	return 0;
}

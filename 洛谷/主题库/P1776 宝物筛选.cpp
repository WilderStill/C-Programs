#include<bits/stdc++.h>
#define M 114514
using namespace std;
int cnt=0,a[M],b[M],f[M],x,y,z,n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&y,&x,&z);
		for(int t=1;t<=z;t<<=1)
		{
			cnt++;         
			a[cnt]=x*t; 
			b[cnt]=y*t;
			z-=t;
		}
		if(z>0)
		{
			a[++cnt]=x*z;
			b[cnt]=y*z;
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=m;j>=a[i];j--)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
	printf("%d",f[m]);
	return 0;
}

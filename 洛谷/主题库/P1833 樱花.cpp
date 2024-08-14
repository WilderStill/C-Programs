#include<bits/stdc++.h>
#define M 11451411
using namespace std;
int c[M],t[M],p[M],f[M],m1,m2,s1,s2,n,tim;
int main()
{
	scanf("%d:%d %d:%d %d",&m1,&s1,&m2,&s2,&n);
	tim=60*(m2-m1)+s2-s1;
	for(int i=1;i<=n;++i)scanf("%d%d%d",&t[i],&c[i],&p[i]);
	for(int i=1;i<=n;++i)
	{
		if(!p[i])
			for(int j=t[i];j<=tim;++j)
				f[j]=max(f[j],f[j-t[i]]+c[i]);
		else
		    for(int k=1;k<=p[i];++k)
		    	for(int j=tim;j>=k*t[i];--j) 
					f[j]=max(f[j],f[j-t[i]]+c[i]);
	}
	printf("%d",f[tim]);
	return 0;
}

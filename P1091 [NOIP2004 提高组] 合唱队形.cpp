#include<bits/stdc++.h>
#define M 1145 
using namespace std;
int n,h[M],f[2][M],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
		scanf("%d",&h[i]);
    h[0]=0;
    for(int i=1;i<=n;++i) 
   		for(int j=0;j<i;++j)
		   	if(h[i]>h[j])
		   		f[0][i]=max(f[0][i],f[0][j]+1);
    h[n+1]=0;
    for(int i=n;i>0;--i)
    	for(int j=n+1;j>i;--j)
			if(h[i]>h[j])
				f[1][i]=max(f[1][i],f[1][j]+1);
    for(int i=1;i<=n;++i)
		ans=max(f[0][i]+f[1][i]-1,ans);
    printf("%d\n",n-ans);
    return 0;
}

#include<bits/stdc++.h>
#define M 1145
using namespace std;
int h[M],t[M],k[M],f[M][M],hn,tn,n;
int main()
{
	scanf("%d%d%d",&hn,&tn,&n);
    for(int i=1;i<=n;++i)scanf("%d%d%d",&h[i],&t[i],&k[i]);
    for(int i=1;i<=n;++i)
    	for(int j=hn;j>=h[i];--j)
    		for(int l=tn;l>=t[i];--l)
        		f[j][l]=max(f[j][l],f[j-h[i]][l-t[i]]+k[i]);
    printf("%d",f[hn][tn]);
    return 0;
}

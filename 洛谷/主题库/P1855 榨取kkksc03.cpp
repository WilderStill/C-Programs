#include<bits/stdc++.h>
#define M 1145
using namespace std;
int n,mcost,tcost,f[M][M],m[M],t[M];
int main()
{
    scanf("%d%d%d",&n,&mcost,&tcost);
    for(int i=1;i<=n;++i)scanf("%d%d",&m[i],&t[i]);
    for(int i=1;i<=n;++i)
        for(int j=mcost;j>=m[i];--j)
	        for(int k=tcost;k>=t[i];--k)
	            f[j][k]=max(f[j][k],f[j-m[i]][k-t[i]]+1);
    printf("%d",f[mcost][tcost]);
    return 0;
}

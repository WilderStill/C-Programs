#include<bits/stdc++.h>
#define M 214
using namespace std;
int SG[M][M],v[M];
int main()
{
    int n,m;
    memset(SG,-1,sizeof SG);
    for(int i=2;i<M;++i)
		for(int j=2;j<M;++j)
		{
			memset(v,0,sizeof(v));
			for(int k=2;i-k>=2;++k)v[SG[k][j]^SG[i-k][j]]=1;
			for(int k=2;j-k>=2;++k)v[SG[i][k]^SG[i][j-k]]=1;
			for(int k=0;k<M;++k)if(!v[k]){SG[i][j]=k;break;}
		}
    while(~scanf("%d%d",&n,&m))puts(SG[n][m]?"WIN":"LOSE");
    return 0;
}

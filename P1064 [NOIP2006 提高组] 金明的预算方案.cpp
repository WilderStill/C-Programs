#include<bits/stdc++.h>
#define M 50348
using namespace std;
int n,m,v,p,q,mw[M],mv[M],aw[M][3],av[M][3],f[M];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
	{
        scanf("%d%d%d",&v,&p,&q);
        if(q)aw[q][0]++,aw[q][aw[q][0]]=v,av[q][aw[q][0]]=v*p;
        else mw[i]=v,mv[i]=v*p;
    }
    for(int i=1;i<=m;i++)
        for(int j=n;mw[i]!=0&&j>=mw[i];j--)
		{
            f[j]=max(f[j],f[j-mw[i]]+mv[i]);
            if(j>=mw[i]+aw[i][1])
                f[j]=max(f[j],f[j-mw[i]-aw[i][1]]+mv[i]+av[i][1]);
            if(j>=mw[i]+aw[i][2])
                f[j]=max(f[j],f[j-mw[i]-aw[i][2]]+mv[i]+av[i][2]);
            if(j>=mw[i]+aw[i][1]+aw[i][2])
                f[j]=max(f[j],f[j-mw[i]-aw[i][1]-aw[i][2]]+mv[i]+av[i][1]+av[i][2]);
         }
     printf("%d",f[n]);
     return 0;
}

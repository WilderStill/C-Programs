#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define M 21451
#define qhd que[hd]
#define qtl que[tl]
using namespace std;
struct node
{
    int x,f,c;
}cow[M];
bool cmp(node a,node b)
{
	return a.c<b.c;
}
int n,k,hd,tl,que[M],f[514][M];
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;++i)scanf("%d%d%d",&cow[i].x,&cow[i].f,&cow[i].c);
    sort(cow+1,cow+n+1,cmp);
    f[0][0]=0;
    for(int i=1;i<=n;++i)
    {
        hd=tl=0;
        for(int j=max(0,cow[i].c-cow[i].x);j<cow[i].c;++j)
        {
            while(hd<=tl&&(f[i-1][qtl]-cow[i].f*qtl)<=(f[i-1][j]-cow[i].f*j))--tl;
            ++tl;
            qtl=j;
        }
        for(int j=1;j<=k;++j)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(j>=cow[i].c)
            {
                while(hd<=tl&&j-cow[i].x>qhd)++hd;
                if(hd<=tl)f[i][j]=max(f[i][j],(f[i-1][qhd]-cow[i].f*qhd)+cow[i].f*j);
			}
        }
    }
    printf("%d",f[n][k]);
    return 0;
}

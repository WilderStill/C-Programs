#include<bits/stdc++.h>
#define M 1145
using namespace std; 
int n,m;
char mp[M][M];
bool col[M][M],edge[M][M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
    for(int i=1,t=0;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='T')t^=1;
            edge[i][j]=t;
        }
    for(int j=1,t=0;j<=m;j++)
        for(int i=1;i<=n;i++)
        {
            if(mp[i][j]=='T')t^=1;
            col[i][j]=t;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<'o'<<(edge[i][j]?'-':' ');
        if(i==n)break;
        cout<<'\n';
        for(int j=1;j<=m;j++)cout<<(col[i][j]?'|':' ')<<' ';
        cout<<'\n';
    }
}

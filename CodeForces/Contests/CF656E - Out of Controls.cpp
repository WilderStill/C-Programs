#include<bits/stdc++.h>
using namespace std;
int mp[1145][1145],n,ans;
int main()
{
scanf("%d",&n);
f\
o\
r(int i=1;i<=n;i++)
f\
o\
r(int j=1;j<=n;j++)
scanf("%d",&mp[i][j]);
f\
o\
r(int k=1;k<=n;k++)
f\
o\
r(int i=1;i<=n;i++)
f\
o\
r(int j=1;j<=n;j++)
mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
f\
o\
r(int i=1;i<=n;i++)
f\
o\
r(int j=1;j<=n;j++)
ans=max(ans,mp[i][j]);
printf("%d",ans);
}

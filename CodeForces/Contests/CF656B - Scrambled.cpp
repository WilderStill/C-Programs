#include<bits/stdc++.h>
using namespace std;
int n,m[127],r[127],ans;
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&m[i]);
    for(int i=1;i<=n;i++)scanf("%d",&r[i]);
    for(int i=1;i<=1e7;i++)
        for(int j=1;j<=n;j++)
            if(i%m[j]==r[j]){ans++;break;}
    printf("%.7lf",ans/1e7);
    return 0;
}

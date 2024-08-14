#include<bits/stdc++.h>
using namespace std;
int f[1145],w[1145],c[1145],v,n,t,p;
vector<int>s[1145];
int main()
{
    scanf("%d%d",&v,&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&w[i],&c[i],&p);
        t=max(t,p); 
        s[p].push_back(i);
    }
    for(int i=1;i<=t;++i)
        for(int j=v;j>=0;--j)
            for(int k=0;k<s[i].size();++k)
                if(w[s[i][k]]<=j)
                    f[j]=max(f[j],f[j-w[s[i][k]]]+c[s[i][k]]);
    printf("%d",f[v]);
    return 0;
}

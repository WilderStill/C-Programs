#include<bits/stdc++.h>
#define ll long long
#define base 131
#define p1 19260817
#define p2 998244353
#define M 11451411
using namespace std;
pair<ll,ll> a[M];
char s[M];
int n,ans=1;
ll hash1()
{
    ll len=strlen(s),res=0;
    for(int i=0;i<len;i++)
        res=(res*base+(ll)s[i])%p1;
    return res;
}
ll hash2()
{
    ll len=strlen(s),res=0;
    for(int i=0;i<len;i++)
        res=(res*base+(ll)s[i])%p2;
    return res;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i]=make_pair(hash1(),hash2());
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        if(a[i].first!=a[i-1].first||a[i-1].second!=a[i].second)
            ans++;
    printf("%d",ans);
}

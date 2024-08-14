#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define M 11451411
using namespace std;
int ans[M],n,f[M];
vector<int>a;
void modify(int x,int val)
{
	for(int i=x;i<=n;i+=lowbit(i))f[i]=max(f[i],val);
}
int query(int x)
{
	int res=0;
    for(int i=x;i;i-=lowbit(i))res=max(res,f[i]);
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),a.insert(x+a.begin(),i);
    for(int i=0;i<n;i++)modify(a[i],ans[a[i]]=query(a[i])+1);
    for(int i=1;i<=n;i++)ans[i]=max(ans[i],ans[i-1]),printf("%d\n",ans[i]);
    return 0;
}

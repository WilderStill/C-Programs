#include <iostream>
using namespace std;
int n,k,a[25];
bool v[25];
long long ans=0;
bool is(int a)
{
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
            return 0;
    return 1;
}
void dfs(int m,int s)
{
    if(m==k)
    {
        if(is(s))
            ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]) continue;
        v[i]=1;
        dfs(m+1,s+a[i]);
        v[i]=0;
    }
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int g=1;
	for(int i=1;i<=k;i++) g*=i;  
	dfs(0,0);
	cout<<ans/g;
	return 0;
} 

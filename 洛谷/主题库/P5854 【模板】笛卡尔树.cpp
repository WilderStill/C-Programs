#include<bits/stdc++.h>
#define ll long long
#define M 10000100
using namespace std;
ll p[M],lson[M],rson[M],stk[M],ans1=0,ans2=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cin.tie(0);
	int n,top=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>p[i];
	for(int i=1;i<=n;++i)
	{
		int k=top;
		while(k&&p[stk[k]]>p[i])--k;
		if(k)rson[stk[k]]=i; 
		if(k<top)lson[i]=stk[k+1];
		stk[++k]=i;
		top=k;
	}
	for(int i=1;i<=n;++i)
	{
		ans1^=((lson[i]+1)*i);
		ans2^=((rson[i]+1)*i);
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}

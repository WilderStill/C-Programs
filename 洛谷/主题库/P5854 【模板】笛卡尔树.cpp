#include<bits/stdc++.h>
#define ll long long
#define M 11451411
using namespace std;
ll n,p[M],lson[M],rson[M];//lson代表笛卡尔树每个节点的左儿子，rson代表笛卡尔树每个节点的右儿子
ll stk[M],ans1=0,ans2=0;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&p[i]);
	int top=0;
	for(ll i=1;i<=n;i++)
	{
		ll k=top;
		while(k>0&&p[stk[k]]>p[i])k--;
		if(k)rson[stk[k]]=i; 
		if(k<top)lson[i]=stk[k+1];
		k++;
		stk[k]=i;
		top=k;
	}
	for(ll i=1;i<=n;i++)
	{
		ans1=ans1^(i*(lson[i]+1));
		ans2=ans2^(i*(rson[i]+1));
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
}

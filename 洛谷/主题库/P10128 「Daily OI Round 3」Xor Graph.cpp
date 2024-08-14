#include<bits/stdc++.h>
#define ll long long
const ll p=998244353;
using namespace std;
ll t,n,a[10000010],q=4;
int main()
{
	cin>>t;
	a[1]=0;
	a[2]=2;
	for(ll i=3;i<=10000000;i++)
	{
		a[i]=(i*(q-1)%p+i*a[i-1]%p)%p;
		q=(q*2)%p;
	}
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}	
}

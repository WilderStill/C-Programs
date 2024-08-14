#include<bits/stdc++.h>
#define M 114514
#define ll long long
using namespace std; 
ll n,f[M][30],a[M],ans;
ll read()
{
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
void print(ll x)
{
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
ll calc()
{
	ll res=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			res+=abs(a[i]-a[f[i][j]]);
	return res/2;
}
void sa()
{
	double t=1000;
	while(t>1e-16)
	{
		ll x=rand()%n+1,y=rand()%n+1,dt;
		swap(a[x],a[y]);
		dt=ans-calc();
		ans=min(ans,calc());
		if(exp(dt)/t<(double)rand()/RAND_MAX)swap(a[x],a[y]);
		t*=0.99;
	}
}

int main()
{
	srand(0);
	n=read();
	for(int i=1;i<=n;i++)
	{
		f[i][1]=read(),f[i][2]=read(),f[i][3]=read();
		a[i]=i;
	}
	ans=INT_MAX;
	for(int i=1;i<=114;i++)sa();
	print(ans);
	return 0;
}

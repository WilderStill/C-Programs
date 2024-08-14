#include<bits/stdc++.h>
#define ll long long
using namespace std;
string k[1145]={"0","2(0)","2","2(2)","2(2+2(0))","2(2(2))","2(2(2)+2(0))","2(2(2)+2)","2(2(2)+2+2(0))","2(2(2+2(0)))","2(2(2+2(0))+2(0))","2(2(2+2(0))+2)","2(2(2+2(0))+2+2(0))","2(2(2+2(0))+2(2))","2(2(2+2(0))+2(2)+2(0))","2(2(2+2(0))+2(2)+2)","2(2(2+2(0))+2(2)+2+2(0))"};
ll p[1145],tot=1,n;
bool fg=0;
void a(ll x)
{
	if(x/2!=0)
	{
		a(x/2);
		p[tot]=x%2;
		tot++;
	}
	else 
	{
		p[tot]=x%2;
		tot++;
	}
}
int main()
{
	scanf("%lld",&n);
	a(n);
	for(int i=tot-1;i>=1;i--)
	{
		if(p[tot-i]&&!fg)
		{
			cout<<k[i];fg++;
		}
		else if(p[tot-i]&&fg)cout<<"+"<<k[i];
	}
}

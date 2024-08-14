#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
bool fg=0;
int main()
{
	scanf("%d",&n);
	while(n>3)
	{
		if(!fg)ans++;
		if(n%3==1)fg=1;
		n=n%3>=1?n-n/3-1:n-n/3;
		p++;
	}
	p+=n;
	if(fg)
	{
		printf("%d %d",p,ans);return 0;
	}
	if(n%3==0)ans+=3;
	if(n%3==1)ans+=1;
	if(n%3==2)ans+=2;
	printf("%d %d",p,ans);
	return 0;
}

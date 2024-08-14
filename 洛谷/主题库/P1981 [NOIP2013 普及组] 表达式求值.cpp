#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
struct node
{
	ll num;
	char op;
	bool vis;
}p[11451411];
int main()
{
	ll tot=0;
	p[tot].op='+';
	while(p[tot].op=='+'||p[tot].op=='*')
	{
		tot++;
		scanf("%lld%c",&p[tot].num,&p[tot].op);
		//printf("%lld %c\n",p[tot].num,p[tot].op);
	}
	for(int i=1,k=1;i<tot;i++)
	{
		if(p[i].op=='*'&&!p[i].vis)
		{
			while(p[i+k].vis)k++;
			p[i+k].num*=p[i].num;
			p[i].vis=1;
			p[i+k].num%=10000;
		}
	}
	for(int i=1;i<=tot;i++)
	{
		if(!p[i].vis)
		{
			//printf("%lld\n",p[i].num);
			ans+=p[i].num;
			ans%=10000;
		}
	}
	printf("%lld",ans);
	return 0;
}

#include<bits/stdc++.h>
#define f first
#define se second
using namespace std;
int n;
stack<pair<int,int> >s;
int main()
{
	scanf("%d",&n);
	long long step=0;
	for(int i=1;i<=n;i++)
	{
		int h;
		scanf("%d",&h);
		pair<int,int> p(h,1);
		for(;!s.empty()&&s.top().f<=h;s.pop())
		{
         	step+=s.top().se;
         	if(s.top().f==h) p.se+=s.top().se;
      	}
      	if(!s.empty())step++;
      	s.push(p);
	}
	printf("%lld\n",step);
	return 0;
}

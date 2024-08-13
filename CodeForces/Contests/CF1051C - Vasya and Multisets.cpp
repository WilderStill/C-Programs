#include<bits/stdc++.h>
using namespace std;
int n,t[110],buc[110],maxn=0,num,cnt1,cnt2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&t[i]);
		buc[t[i]]++;
	}
	for(int i=1;i<=100;++i)
	{
		if(buc[i])++num;
		if(buc[i]==1)++cnt1;
		if(buc[i]==2)++cnt2;
	}
	if(!(cnt1&1))
	{
		puts("YES");
		bool fg=0;
		for(int i=1;i<=n;++i)
		{
			if(buc[t[i]]==1)putchar(!fg?'A':'B'),fg=!fg;
			else putchar('A');
		}
	}
	else
	{
		if(cnt1+cnt2==num)puts("NO");
		else
		{
			puts("YES");
			bool fg=0,vis=0;
			for(int i=1;i<=n;++i)
			{
				if(buc[t[i]]==1)putchar(!fg?'A':'B'),fg=!fg;
				else if(buc[t[i]]==2)putchar('A');
				else if(!vis)putchar('B'),vis=1;
				else putchar('A');
			}
		}
	}
    return 0;
}

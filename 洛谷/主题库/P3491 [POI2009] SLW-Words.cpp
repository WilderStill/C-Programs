#include<bits/stdc++.h>
using namespace std;
int num[100010];
int main()
{
	int T;
	scanf("%d",&T); 
	while(T--)
	{
		bool fg=1;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&num[i]);
		while(n>1&&fg)
		{
			if(!num[1])num[1]=2;
			if(num[n]==1)--n;
			else if(num[n]==3)num[n]=2;
			for(int i=n;i;--i)
				if(!num[i]) 
				{
					if(num[i-1]==1)num[i-1]=2;
					else if(num[i-1]==3)num[i-1]=num[i]=2;
					else
					{
						fg=0;
						break;
					}
				}
			int tp=0;
			for(int i=1;i<=n;++i)if(num[i])num[++tp]=num[i];
			n=tp;
			for(int i=1;i<=n;++i)--num[i];
		}
		puts(fg?"TAK":"NIE");
	}
	return 0;
}

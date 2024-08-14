#include<bits/stdc++.h>
using namespace std;
int x,y,tot,ans;
bool fg=1;
int main()
{
	scanf("%d",&x);
	int y=x;
	for(int i=2,cnt=0;i<=sqrt(x);++i,cnt=0)
	{
	    if(!(x%i))
		{
	        while(!(x%i))++cnt,x/=i;
	        if(!tot)ans=i;
			++tot;
	        if(cnt>=2)fg=0;
	    }
	}
	if(x>1)++tot;
	if(tot==1)printf("%d",y);
	else if(fg&&tot%2)printf("%d",ans);
	else printf("1");
	return 0;
}

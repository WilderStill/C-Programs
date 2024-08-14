#include<bits/stdc++.h>
using namespace std;
struct tit
{
    int prc;
	int tm;
	bool ud;
}t[1145141];
int l,r,n,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1,kd,prc,tm;i<=n;i++)
	{
		scanf("%d%d%d",&kd,&prc,&tm);
        if(!kd)
		{
            ans+=prc;
            t[r].tm=tm+45;
            t[r].prc=prc;
            r++;
        }
		else
		{
            while(l<r&&t[l].tm<tm)l++;
            bool fg=0;
            for(int j=l;j<r;j++)
			{
                if(t[j].prc>=prc&&!t[j].ud)
				{
                    fg=1,t[j].ud=1;
                    break;
                }
            }
            if(!fg) ans+=prc;
        }
    }
    printf("%d",ans);
    return 0;
}

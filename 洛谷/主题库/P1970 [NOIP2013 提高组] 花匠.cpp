#include<bits/stdc++.h>
using namespace std;
int n,h[11451411],ans=1;
bool fg;
int main()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&h[i]);
	if(n==1)
	{
		printf("1");
		return 0;
	}
    if(h[2]>=h[1]) fg=1;
    for(int i=1;i<=n;i++)
    {
        if(!fg)
		{
			if(i==n)
			{
				ans++;
				break;
			} 
			else if(h[i+1]>h[i])
				ans++,fg=1;
		}
		else
			if(h[i+1]<h[i])
				ans++,fg=0;
    }
    printf("%d",ans); 
    return 0;
}

#include<bits/stdc++.h>
#define M 11451411
using namespace std;
int n,cnt,tot;
bool isp[M];
int prime[M];
void phi()
{
    for(int i=2;i<=M;i++)
	{
        if(!isp[i])prime[++tot]=i;
        for(int j=1;prime[j]*i<=M&&j<=tot;j++)
		{
            isp[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
	scanf("%d",&n);
	phi();
	for(int i=2;i<=M;i++)
	{
		int x=0,t=i;
		while(t)
		{
			x=x*10+t%10;
			t/=10;
		}
		if(x==i) continue;
		if(!isp[i]&&!isp[x])cnt++;
		if(cnt==n){printf("%d",i);break;}
	}
	return 0;
}

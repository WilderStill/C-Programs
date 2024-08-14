#include<bits/stdc++.h>
int ipv6[14],len[14]; 
using namespace std;
int main()
{
	for(int i=1;i<=8;i++)
	{
		scanf("%x",&ipv6[i]);
		getchar();
	}
	int cnt=1,maxn;
	for(int i=1;i<=8;i++)
	{
		if(ipv6[i]!=0)cnt=i+1;
		else len[cnt]++;
	}
	maxn=0,cnt=0;
	for(int i=1;i<=8;i++)
	{
		if(len[i]>maxn)cnt=i,maxn=len[i];
	}
	for(int i=1;i<=8;i++)
	{
		if(i==cnt)
		{
			printf(":"),i+=maxn;
			if(i>8)
			{
				printf(":");break;
			}
		}
		if(i-1)printf(":");
		printf("%x",ipv6[i]);
	} 
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n,mss,sum,nsum;//mss->MaxSubSum
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		mss=sum=nsum=0;
		scanf("%d",&n);
		for(int i=1,tmp;i<=n;i++)
		{
			scanf("%d",&tmp);
			sum+=tmp;nsum+=tmp;
			if(nsum<0)nsum=0;
			else mss=max(mss,nsum);
		}
		printf("%d\n",mss*2-sum);
	}
	return 0;
}

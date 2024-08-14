#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int main()
{
	scanf("%lld%lld",&n,&m);
	if(n==1)
	{
		printf("%lld\n",m);
		for(int i=1;i<=m;i++)printf("%lld ",i);
	}
	if(n==2)
	{
		if(m%2==0)printf("%lld\n",m+m/2);
		else printf("%lld\n",m+m/2+1);
		for(int i=1;i<=m;i++)printf("%lld ",i);
		printf("\n");
		int i,j;
		for(i=2,j=0;i<=m;i+=2,j++)
		{
			printf("%d -1 ",m+j+1);
		}
		if(i==m+1)printf("%d",m+j+1);
	}
	if(n==3)
	{
		if(m==1)
		{
			printf("3\n1\n2\n3");return 0;
		}
		cnt=0;
		for(int i=1;i<=m;i++)cnt++;
		for(int i=1;i<=m;i++)if(i%2==1)cnt++;
		for(int i=1;i<=m;i++)if(i%4!=3)cnt++;
		printf("%lld\n",cnt);
		cnt=m;
		for(int i=1;i<=m;i++)printf("%lld ",i);
		printf("\n");
		for(int i=1;i<=m;i++)
		{
			if(i%2==1)printf("%lld ",++cnt);
			else printf("-1 ");
		}
		printf("\n%lld ",++cnt);
		for(int i=2;i<=m;i++)
		{
			if(i==m)
			{
				if(i%4==0){printf("%d ",++cnt);}
				else if(i%4==1){printf("%d ",++cnt-1);}
				else if(i%4==2){printf("%d ",++cnt);}
				else if(i%4==3){printf("-1 ");}	
			}
			else 
			{
				if(i%4==0){printf("%d ",++cnt+1);}
				else if(i%4==1){printf("%d ",++cnt-1);}
				else if(i%4==2){printf("%d ",++cnt);}
				else if(i%4==3){printf("-1 ");}
			}
		}
		printf("\n");
		
	}
	return 0;
} 

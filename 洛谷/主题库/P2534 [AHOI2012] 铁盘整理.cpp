#include<bits/stdc++.h>
using namespace std;
int n,a[20],b[20],maxd;
bool fg;
int value()
{
	int val=0;
	for(int i=1;i<=n;++i)
		if(abs(a[i]-a[i+1])!=1)++val;
	return val;
}
void dfs(int x,int val,int step)
{
	if(step==maxd)
	{
		if(!val)fg=1;
		return;
	}
	int tmp;
	for(int i=2;i<=n;++i)
	{
		if(i==x||abs(a[i+1]-a[i])==1)continue;
		tmp=val;
		reverse(a+1,a+i+1);
		if(abs(a[i]-a[i+1])==1)tmp=val-1; 
		if(tmp+step<=maxd)
		{
			dfs(i,tmp,step+1);
			if(fg)return;
		}
		reverse(a+1,a+i+1); 
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	a[n+1]=n+1;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(maxd=0;;++maxd)
	{
		dfs(1,value(),0);
		if(fg){printf("%d",maxd);return 0;}
	}
	
}

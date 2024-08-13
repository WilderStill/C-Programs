#include<bits/stdc++.h>
using namespace std;
int t,f[11451411];
void init()
{
	int n=1;
	for(int i=2;i<=1500;i++)
	{
		f[n]=i-1;n++;
		for(int j=i-2;j>0;j--)
		{
			f[n]=i;
			n++;
		}
		f[n]=i+1;n++;
	}
}
int main()
{
	scanf("%d",&t);
	init();
	//for(int i=1;i<=11451411;i++)cout<<","<<f[i];
	while(t--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",f[a]);
	} 
	return 0;
}

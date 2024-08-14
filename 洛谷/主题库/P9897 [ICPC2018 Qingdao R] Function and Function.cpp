#include<bits/stdc++.h>
using namespace std;
int g(int k,int x)
{
	if(k==0)return x;
	if(x<10&&k>=2)
	{
		if(x==0||x==4||x==6||x==9||x==8)return (k%2)?1:0;
		else return (k%2)?0:1;
	}
	int res=0,t;
	if(x==0)res=1;
	while(x)
	{
		t=x%10;
		if(t==0||t==4||t==6||t==9)res++;
		else if(t==8)res+=2;
		x/=10;
	}
	if(k==1)return res;
	else return g(k-1,res);
}
int main()
{
	int T,k,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&k);
		printf("%d\n",g(k,x));
	}
	return 0;
}

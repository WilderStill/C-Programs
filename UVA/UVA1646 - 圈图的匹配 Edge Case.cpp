#include<bits/stdc++.h>
using namespace std;
struct long_long
{
	int len,num[11451];
	inline void f(){memset(num,0,sizeof(num));}
	friend long_long operator +(const long_long&a,const long_long&b)
	{
		long_long res;
		res.f();
		res.len=max(a.len,b.len);
		for(int i=1;i<=res.len;i++)
		{
			res.num[i]=a.num[i]+b.num[i]+res.num[i];
			res.num[i+1]+=res.num[i]/10;
			res.num[i]%=10;
		}
		if(res.num[res.len+1])res.len++;
		return res;
	}
}a[11451],ans;
int main()
{
	int n;
	a[0].len=0;a[0].f();
	a[1].len=1;a[1].num[1]=1;
	a[2].len=1;a[2].num[1]=2;
	for(int i=3;i<=10145;i++)a[i]=a[i-1]+a[i-2];
	while(scanf("%d",&n)!=EOF)
	{
		ans=a[n]+a[n-2];
		for(int i=ans.len;i;i--)printf("%d",ans.num[i]);
		printf("\n");
	}
	return 0;
}

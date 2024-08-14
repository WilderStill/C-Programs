#include<bits/stdc++.h>
#define mod ((long long)pow(2,31))
#define M 114
using namespace std;
int f[M],n,cnt=0;
int main()
{
	scanf("%d",&n);
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2]+mod)%mod;
	printf("%d=",f[n]);
	for(int i=2;i<=f[n];i++)
		while(!(f[n]%i))
		{
			cnt++;
			if(cnt==1)printf("%d",i);
			else printf("*%d",i);
			f[n]/=i;
		}
	return 0;                       
}

#include<bits/stdc++.h>
using namespace std;
int f[1001][1001],m,n,len=1;
int main()
{
	scanf("%d%d",&m,&n);n=n-m;
	if(n<=2){putchar('1');return 0;}
	f[1][1]=1,f[2][1]=2;
	for(int i=3;i<=n;++i)
	{
		for(int j=1;j<=len;++j)f[i][j]=f[i-1][j]+f[i-2][j];
		for(int j=1;j<=len;++j)
			if(f[i][j]>9)
				f[i][j+1]+=f[i][j]/10,f[i][j]=f[i][j]%10;
		if(f[i][len+1]>0)++len;
	}
	++len;
	while(--len)putchar(f[n][len]+'0');
	return 0;
}

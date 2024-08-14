#include<bits/stdc++.h>
using namespace std;
int a[12][12][12][12][12],n,ans,p[10];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n;++i)
	{
		for(int j=1;j<6;++j)scanf("%d",&p[j]);
		for(int j=1;j<10;++j)
		{
			a[(p[1]+j)%10][p[2]][p[3]][p[4]][p[5]]++;
			a[p[1]][(p[2]+j)%10][p[3]][p[4]][p[5]]++;
			a[p[1]][p[2]][(p[3]+j)%10][p[4]][p[5]]++;
			a[p[1]][p[2]][p[3]][(p[4]+j)%10][p[5]]++;
			a[p[1]][p[2]][p[3]][p[4]][(p[5]+j)%10]++;
			a[(p[1]+j)%10][(p[2]+j)%10][p[3]][p[4]][p[5]]++;
			a[p[1]][(p[2]+j)%10][(p[3]+j)%10][p[4]][p[5]]++;
			a[p[1]][p[2]][(p[3]+j)%10][(p[4]+j)%10][p[5]]++;
			a[p[1]][p[2]][p[3]][(p[4]+j)%10][(p[5]+j)%10]++;
		}
	}
	for(int i1=0;i1<=9;++i1)
		for(int i2=0;i2<=9;++i2)
			for(int i3=0;i3<=9;++i3)
				for(int i4=0;i4<=9;++i4)
					for(int i5=0;i5<=9;++i5)
						if(a[i1][i2][i3][i4][i5]==n)
							++ans;
	printf("%d",ans);
	return 0;
}

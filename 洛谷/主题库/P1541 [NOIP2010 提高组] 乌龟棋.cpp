#include<bits/stdc++.h>
using namespace std;
int f[145][145][145][145],m,n,a[11451411],b[5];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),b[x]++;
	f[0][0][0][0]=a[1];
	for(int i1=0;i1<=b[1];i1++)
		for(int i2=0;i2<=b[2];i2++)
			for(int i3=0;i3<=b[3];i3++)
				for(int i4=0;i4<=b[4];i4++)
				{
					int tmp=1+i1*1+i2*2+i3*3+i4*4;
					if(i1)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]+a[tmp]);
					if(i2)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]+a[tmp]);
					if(i3)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]+a[tmp]);
					if(i4)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]+a[tmp]);
				}
	printf("%d",f[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}

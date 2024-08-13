#include <bits/stdc++.h>
using namespace std;
int a,f[1145141];
int main()
{
	scanf("%d",&a);
	f[1]=1;
	for(int i=2;i<=a;i++)f[i]=(i*2-1)*6+f[i-1]-6;
	printf("%d",f[a]);
    return 0;
}

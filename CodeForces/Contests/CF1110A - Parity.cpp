#include<bits/stdc++.h>
using namespace std;
int b,k,sum,a[114514];
int main()
{
	scanf("%d%d",&b,&k);
	for(int i=1;i<=k;++i)
    {
        scanf("%d",&a[i]);
        if(b&1&&a[i]&1)sum++;
    }
    if(!(b&1)&&a[k]&1)sum++;
	puts(sum&1?"odd":"even");
	return 0;
} 

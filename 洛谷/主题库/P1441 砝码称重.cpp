#include<bits/stdc++.h>
using namespace std;
bitset<1145>bits;
int m,n,a[30],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<(1<<n);i++)
        if(__builtin_popcount(i)==n-m)
		{
            bits.reset();
			bits[0]=1;
            for(int j=0;j<n;j++)if(i&(1<<j))bits|=bits<<a[j];
            ans=max(ans,(int)bits.count());
        }
    printf("%d",ans-1);
	return 0;
}

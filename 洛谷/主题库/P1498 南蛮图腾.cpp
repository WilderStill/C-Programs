#include<bits/stdc++.h>
using namespace std;
int n,ter[11451411];
int main()
{
	scanf("%d",&n);
	ter[0]=1;
    for(int i=0;i<(1<<n);i++)
	{
        for(int j=1;j<(1<<n)-i;j++)printf(" ");
		for(int j=i;j>=0;j--)ter[j]^=ter[j-1];
		if(i%2)for(int j=0;j<=i;j+=2)printf(ter[j]?"/__\\":"    ");
		else for(int j=0;j<=i;j++)printf(ter[j]?"/\\":"  ");
		printf("\n");
    }
    return 0;
}

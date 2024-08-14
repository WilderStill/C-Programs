#include<bits/stdc++.h>
using namespace std;
int n,p,num[300010];
int mini()
{
	int i=1,j=2,k=0;
    while(i<=n&&j<=n&&k<=n)
    {
    	if(num[(i+k)%n+1]==num[(j+k)%n+1])k++;
    	else
    	{
	    	if(num[(i+k)%n+1]>num[(j+k)%n+1])i+=(k+1);
	    	else j+=(k+1);
	    	if(i==j)i++; 
	    	k=0;
		}
	}
    return min(i,j);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	p=mini();
	for(int i=0;i<n;i++)printf("%d ",num[(i+p)%n+1]);
	return 0;
}
